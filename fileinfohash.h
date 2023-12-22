#ifndef FILEINFOHASH_H
#define FILEINFOHASH_H

#include <QString>
#include <QFileInfo>
#include <QCryptographicHash>

class FileInfoHash: public QFileInfo {
public:
    FileInfoHash();
    FileInfoHash(const QString &filepath);
    ~FileInfoHash();
    QByteArray MD5() const;
    QByteArray SHA1() const;
    QByteArray SHA256() const;

private:
    QByteArray md5;
    QByteArray sha1;
    QByteArray sha256;

    void calculateHashes();
};


#endif // FILEINFOHASH_H
