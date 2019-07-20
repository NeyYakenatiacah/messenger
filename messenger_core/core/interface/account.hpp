#ifndef ACCOUNT_INTERFACE_H
#define ACCOUNT_INTERFACE_H

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

#endif // ACCOUNT_INTERFACE_H
