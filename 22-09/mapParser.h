#ifndef MAPPARSER_H
#define MAPPARSER_H

#pragma once
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

struct MemoryRegion
{
    QString name;
    quint32 origin;
    quint32 length;
    QString attrs;
    quint32 used = 0;
};

struct SectionPlacement
{
    QString section;
    quint32 addr;
    quint32 size;
    QString regionName;
};



class MapParser
{
public:

    bool ParseFile(const QString &path, QString *error);
    const QVector<MemoryRegion>&regions() const {return m_regions;}
    const QVector<SectionPlacement>&sections()const{return m_sections;}

private:
    QVector<MemoryRegion> m_regions;
    QVector<SectionPlacement> m_sections;

};

#endif // MAPPARSER_H
