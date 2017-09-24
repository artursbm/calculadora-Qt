#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
Q_OBJECT
public:
    explicit Calculator(QObject *parent = 0);

public slots:
    void numEntered(int);

    void clear();
    void allClear();

    void additionMode();
    void subtractionMode();
    void multiplicationMode();
    void divisionMode();

    void calculate();

signals:
    void displayChanged(QString);

private:
    double m_lastResult;
    double m_currentNumber;
    bool m_isAdding = false;
    bool m_isSubtracting = false;
    bool m_isMultiplying = false;
    bool m_isDividing = false;
};

#endif // CALCULATOR_H
