#include "calculator.h"

Calculator::Calculator(QObject *parent) :
    QObject(parent), m_lastResult(0), m_currentNumber(0), m_isAdding(true), m_isMultiplying(true), m_isDividing(true)
{}

void Calculator::numEntered(int num)
{
    m_leftNumber = m_currentNumber;
    m_currentNumber = m_leftNumber*10 + num;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::clear()
{
    m_leftNumber = 0;
    m_currentNumber = 0;
    m_isAdding = false;
    m_isSubtracting = false;
    m_isMultiplying = false;
    m_isDividing = false;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::allClear()
{
    m_lastResult = 0;
    clear();
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::additionMode()
{
    calculate();
    m_isAdding = true;
}

void Calculator::subtractionMode()
{
    calculate();
    m_isSubtracting = true;
}

void Calculator::multiplicationMode() {
    calculate();
    m_isMultiplying = true;
}

void Calculator::divisionMode() {
    calculate();
    m_isDividing = true;
}

void Calculator::calculate()
{
    if(m_isAdding)  {
        m_leftNumber += m_currentNumber;
        m_lastResult += m_leftNumber;
    }
    else if(m_isSubtracting) {
        m_leftNumber += m_currentNumber;
        m_lastResult -= m_leftNumber;
    }
    else if(m_isMultiplying) {
        m_leftNumber += m_currentNumber;
        m_lastResult *= m_leftNumber;
    }
    else if(m_isDividing) {
        m_leftNumber += m_currentNumber;
        m_lastResult /= m_leftNumber;
    }
    m_currentNumber = 0;
    m_isAdding = false;
    m_isSubtracting = false;
    m_isMultiplying = false;
    m_isDividing = false;
    emit displayChanged(QString::number(m_lastResult));
}
