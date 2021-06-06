#include "organyahelper.h"
#include "decoder_organya.h"
#include "decoderorganyafactory.h"

bool DecoderOrganyaFactory::canDecode(QIODevice *) const
{
    return false;
}

DecoderProperties DecoderOrganyaFactory::properties() const
{
    DecoderProperties properties;
    properties.name = "Organya Plugin";
    properties.shortName = "organya";
    properties.filters << "*.org";
    properties.description = "Cave Story's org Audio File";
    properties.protocols << "file";
    properties.noInput = true;
    return properties;
}

Decoder *DecoderOrganyaFactory::create(const QString &path, QIODevice *input)
{
    Q_UNUSED(input);
    return new DecoderOrganya(path);
}

QList<TrackInfo*> DecoderOrganyaFactory::createPlayList(const QString &path, TrackInfo::Parts parts, QStringList *)
{
    TrackInfo *info = new TrackInfo(path);

    if(parts == TrackInfo::Parts())
    {
        return QList<TrackInfo*>() << info;
    }

    OrganyaHelper helper(path);
    if(!helper.initialize())
    {
        delete info;
        return QList<TrackInfo*>();
    }

    if(parts & TrackInfo::Properties)
    {
        info->setValue(Qmmp::BITRATE, helper.bitrate());
        info->setValue(Qmmp::SAMPLERATE, helper.sampleRate());
        info->setValue(Qmmp::CHANNELS, helper.channels());
        info->setValue(Qmmp::BITS_PER_SAMPLE, helper.bitsPerSample());
        info->setValue(Qmmp::FORMAT_NAME, "Organya");
        info->setDuration(helper.totalTime());
    }

    return QList<TrackInfo*>() << info;
}

MetaDataModel* DecoderOrganyaFactory::createMetaDataModel(const QString &path, bool readOnly)
{
    Q_UNUSED(path);
    Q_UNUSED(readOnly);
    return nullptr;
}

void DecoderOrganyaFactory::showSettings(QWidget *parent)
{
    Q_UNUSED(parent);
}

#ifndef QMMP_GREATER_NEW
#include <QtPlugin>
Q_EXPORT_PLUGIN2(organya, DecoderOrganyaFactory)
#endif
