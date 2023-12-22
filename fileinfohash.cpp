#include "fileinfohash.h"

FileInfoHash::FileInfoHash() {}
FileInfoHash::~FileInfoHash() {}
FileInfoHash::FileInfoHash(const QString &filepath)
    : QFileInfo(filepath) {
    calculateHashes();
}

QByteArray FileInfoHash::MD5() const{
    return md5;
}

QByteArray FileInfoHash::SHA1() const {
    return sha1;
}

QByteArray FileInfoHash::SHA256() const {
    return sha256;
}

void FileInfoHash::calculateHashes() {
    QFile file(filePath());
    if (file.open(QIODevice::ReadOnly)) {
        QCryptographicHash md5Hash(QCryptographicHash::Md5);
        QCryptographicHash sha1Hash(QCryptographicHash::Sha1);
        QCryptographicHash sha256Hash(QCryptographicHash::Sha256);

        QByteArray buffer;
        qint64 bufferSize = 8192;

        while (!file.atEnd())
        {
            buffer = file.read(bufferSize);
            md5Hash.addData(buffer);
            sha1Hash.addData(buffer);
            sha256Hash.addData(buffer);
        }

        md5 = md5Hash.result();
        sha1 = sha1Hash.result();
        sha256 = sha256Hash.result();

        file.close();
    }
}
