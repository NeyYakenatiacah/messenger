#ifndef USER_DATA_H
#define USER_DATA_H

#include <QObject>
#include <QDate>

namespace core
{
class UserData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY nicknameChanged)
    Q_PROPERTY(QDate   birthday READ birthday WRITE setBirthday NOTIFY birthdayChanged)

public:
    explicit UserData(QObject * parent = nullptr);

    QString nickname() const;
    void setNickname(const QString &nickname);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

signals:
    void nicknameChanged();
    void birthdayChanged();

private:
    QString m_nickname;
    QDate m_birthday;
};
}

#endif // USER_DATA_H
