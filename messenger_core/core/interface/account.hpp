#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <QObject>

namespace core
{
class AccountInterface : public QObject
{
    Q_OBJECT
public:
    explicit AccountInterface(QObject *parent = nullptr);

signals:

public slots:
};
}

#endif // ACCOUNT_HPP
