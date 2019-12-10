#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
using namespace std;
namespace dp {
    class DataProcessor : public QObject
    {
        Q_OBJECT
    public:
        DataProcessor();
        DataProcessor(QByteArray data);
        virtual void update(QByteArray &data)=0;
        QByteArray data;

    signals:

    public slots:
    };
}


#endif // DATAPROCESSOR_H
