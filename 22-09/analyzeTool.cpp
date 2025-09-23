#include "analyzeTool.h"
#include "./ui_analyzetool.h"

AnalyzeTool::AnalyzeTool(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnalyzeTool)
{
    ui->setupUi(this);
}

AnalyzeTool::~AnalyzeTool()
{
    delete ui;
}

void AnalyzeTool::on_btnOpenMap_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Map dosyası seç", "", "Map Files (*.map);;All Files (*)");

    if(fileName.isEmpty())
    {
        return;
    }

    MapParser parser;
    QString err;

    if(!parser.ParseFile(fileName, &err))
    {
        ui->txtOutput->setPlainText("Hata: " + err);
        return;
    }

    QString out;
    out += "===MEMORY REGIONS ===\n";
    for(const auto &r : parser.regions())
    {
        out += QString("%1: origin=0x%2, length=0x%3, attrs=%4\n")
        .arg(r.name)
        .arg(r.origin,0,16)
        .arg(r.length,0,16)
                   .arg(r.attrs);
    }

    out += "===SECTIONS===\n";

    for(const auto &s : parser.sections())
    {
        out +=QString("%1 at 0x%2 size=0x%3\n")
        .arg(s.section)
        .arg(s.addr,0,16)
                   .arg(s.size,0,16);
    }
    ui->txtOutput->setPlainText(out);
}
