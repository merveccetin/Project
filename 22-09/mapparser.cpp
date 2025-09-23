#include "mapParser.h"

bool MapParser::ParseFile(const QString &p, QString *err) // p açılacak dosyanın yolu, err hata mesajını döndürmek için bir pointer.
{
    m_regions.clear(); // daha önceki pars sonuçlarını siler.yeni
    m_sections.clear();

    QFile f(p); // f dosya nesnesi, parametre olarak verilen p yolundaki dosya ile ilişkilendirilir.
    if(!f.open(QIODevice::ReadOnly |QIODevice::Text ))
    {
        if(err) *err = "Dosya Açılamadı. ";
        return false;
    }
    QTextStream in(&f);
    enum State {None, Mem, Sec};
    State st = None;

    QRegularExpression reMem (R"(^\s*(\w+)\s+origin:\s*(0x[0-9A-Fa-f]+)\s+length:\s*(0x[0-9A-Fa-f]+)\s+attributes:\s*(\S+))");

    QRegularExpression reSec(
        R"(^\s*(\.\S+)\s+\S+\s+(0x[0-9A-Fa-f]+)\s+(0x[0-9A-Fa-f]+))");

    while(!in.atEnd())
    {
        QString line = in.readLine();
        if(line.contains("MEMORY CONFIGURATION"))
        {
            st = Mem;
            continue;
        }
        if(line.contains("SECTION ALLOCATION MAP"))
        {
            st = Sec;
            continue;
        }

        if(st == Mem)
        {
            auto m= reMem.match(line);

            if(m.hasMatch())
            {
                MemoryRegion r;
                r.name = m.captured(1);
                r.origin = m.captured(2).toUInt(nullptr,16);
                r.length = m.captured(3).toUInt(nullptr,16);
                r.attrs = m.captured(4);
                m_regions.push_back(r);

            }
        }

        else if(st == Sec)
        {
            auto m = reSec.match(line);

            if(m.hasMatch())
            {
                SectionPlacement s;
                s.section = m.captured(1);
                s.addr = m.captured(2).toUInt(nullptr,16);
                s.size = m.captured(3).toUInt(nullptr,16);
                //şimdilik region eşleşmesi yapmıyoruz
                m_sections.push_back(s);
            }
        }
    }
    return true;
}
