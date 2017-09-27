#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QtMath>

class Calculator : public QObject
{
Q_OBJECT
public:
    explicit Calculator(QObject *parent = 0);

public slots:
    void numEntered(int);
    void constEntered(QString);

    void clear();
    void allClear();
    void equalMode();

    void additionMode();
    void subtractionMode();
    void multiplicationMode();
    void divisionMode();
    void sqrtMode();
    void squareMode();
    void cubeMode();
    void exponentMode();
    void sinMode();
    void cosMode();
    void tgMode();
    void neperlogMode();
    void logMode();
    void neperexpMode();

    void calculate();

signals:
    void displayChanged(QString);

private:

    void setAllOp();
    void resetAllOp();
    double m_lastResult;
    double m_currentNumber;
    bool m_isEqual = false;
    bool m_isAdding = false;
    bool m_isSubtracting = false;
    bool m_isMultiplying = false;
    bool m_isDividing = false;
    bool m_isSqrting = false;
    bool m_isSquaring = false;
    bool m_isCubing = false;
    bool m_isExponenting = false;
    bool m_isSining = false;
    bool m_isCosing = false;
    bool m_isTangenting = false;
    bool m_isNeperloging = false;
    bool m_isLoging = false;
    bool m_isNeperexping = false;

};

#endif // CALCULATOR_H
