#ifndef ANALYZETOOL_H
#define ANALYZETOOL_H

#include <QMainWindow>
#include <QFileDialog>
#include "mapParser.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class AnalyzeTool;
}
QT_END_NAMESPACE

class AnalyzeTool : public QMainWindow
{
    Q_OBJECT

public:
    AnalyzeTool(QWidget *parent = nullptr);
    ~AnalyzeTool();

private slots:
    void on_btnOpenMap_clicked();
private:
    Ui::AnalyzeTool *ui;
};
#endif // ANALYZETOOL_H
