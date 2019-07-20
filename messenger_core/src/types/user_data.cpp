#include <core/types/user_data.h>

namespace core
{
UserData::UserData(QObject *parent)
    : QObject(parent)
{

}

QString UserData::nickname() const
{
    return m_nickname;
}

void UserData::setNickname(const QString &nickName)
{
    m_nickname = nickName;
}

QDate UserData::birthday() const
{
    return m_birthday;
}

void UserData::setBirthday(const QDate &birthday)
{
    m_birthday = birthday;
}
}
