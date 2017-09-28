#include "calculator.h"

Calculator::Calculator(QObject *parent) :
    QObject(parent), m_lastResult(0), m_currentNumber(0),
    m_isAdding(true),
    m_isSubtracting(true),
    m_isMultiplying(true),
    m_isDividing(true),
    m_isSqrting(true),
    m_isSquaring(true),
    m_isCubing(true),
    m_isExponenting(true),
    m_isSining(true),
    m_isCosing(true),
    m_isTangenting(true),
    m_isNeperloging(true),
    m_isLoging(true),
    m_isNeperexping(true),
    m_isDecimal(false),
    m_isFirstTime(true)
{
}

void Calculator::setAllOp(){
    m_isEqual = true;
    m_isAdding = true;
    m_isSubtracting = true;
    m_isMultiplying = true;
    m_isDividing = true;
    m_isSqrting = true;
    m_isSquaring = true;
    m_isCubing = true;
    m_isExponenting = true;
    m_isSining = true;
    m_isCosing = true;
    m_isTangenting = true;
    m_isNeperloging = true;
    m_isLoging = true;
    m_isNeperexping = true;
    m_isDecimal = false;
    m_isFirstTime = true;
}

void Calculator::resetAllOp(){
    m_isEqual = false;
    m_isAdding  = false;
    m_isSubtracting  = false;
    m_isMultiplying  = false;
    m_isDividing  = false;
    m_isSqrting  = false;
    m_isSquaring  = false;
    m_isCubing  = false;
    m_isExponenting  = false;
    m_isSining  = false;
    m_isCosing  = false;
    m_isTangenting  = false;
    m_isNeperloging  = false;
    m_isLoging  = false;
    m_isNeperexping  = false;
    m_isDecimal = false;
    m_isFirstTime = true;
}

void Calculator::numEntered(QString num)
{

    if (m_isFirstTime){
        m_numAux = "";
        m_isFirstTime = false;
    }

    if(!m_isDecimal && num =="."){
        m_numAux += ".";
        m_isDecimal = true;
    }
    else if (num != "."){
        m_numAux += num;

    }
    m_currentNumber = m_numAux.toFloat();
    emit displayChanged(m_numAux);
}

//void Calculator::decimalMode(QString num) {
//    QString currentNumber = QString::number(m_currentNumber);
//    QString result = strcat(currentNumber, ".");
//    result = strcat(result, num);
//    emit displayChanged(QString::number(result));
//}

void Calculator::signalMode() {
    m_currentNumber = -m_currentNumber;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::constEntered(QString num)
{
    m_numAux = "";
    m_currentNumber = num.toFloat();
    emit displayChanged(QString::number(m_currentNumber,'f',10));
}

void Calculator::clear()
{
    m_currentNumber = 0;
    setAllOp();
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::allClear()
{
    m_currentNumber = 0;
    m_lastResult = 0;
    setAllOp();
    emit displayChanged(QString::number(m_currentNumber));

}

void Calculator::equalMode()
{
    calculate();
    m_isEqual = true;
    setAllOp();
    m_currentNumber = 0;
    m_lastResult = 0;
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

void Calculator::sqrtMode() {
    calculate();
    m_isSqrting = true;
}

void Calculator::squareMode() {
    calculate();
    m_isSquaring = true;
}

void Calculator::cubeMode() {
    calculate();
    m_isCubing = true;
}

void Calculator::exponentMode() {
    calculate();
    m_isExponenting = true;
}

void Calculator::sinMode() {
    calculate();
    m_isSining = true;
}

void Calculator::cosMode() {
    calculate();
    m_isCosing = true;
}

void Calculator::tgMode() {
    calculate();
    m_isTangenting = true;
}

void Calculator::neperlogMode() {
    calculate();
    m_isNeperloging = true;
}

void Calculator::logMode() {
    calculate();
    m_isLoging = true;
}

void Calculator::neperexpMode() {
    calculate();
    m_isNeperexping = true;
}

void Calculator::calculate()
{
    if(m_isAdding)  m_lastResult += m_currentNumber;
    else if(m_isSubtracting)    m_lastResult -= m_currentNumber;
    else if(m_isMultiplying)    m_lastResult *= m_currentNumber;
    else if(m_isDividing)   m_lastResult /= m_currentNumber;
    else if(m_isSqrting)   m_lastResult = qSqrt(m_lastResult);
    else if(m_isSquaring)   m_lastResult = m_lastResult * m_lastResult;
    else if(m_isCubing)   m_lastResult = m_lastResult * m_lastResult * m_lastResult;
    else if(m_isExponenting)   m_lastResult = qPow(m_lastResult, m_currentNumber);
    else if(m_isSining)   m_lastResult = qSin(m_lastResult);
    else if(m_isCosing)   m_lastResult = qCos(m_lastResult);
    else if(m_isTangenting)   m_lastResult = qTan(m_lastResult);
    else if(m_isNeperloging)   m_lastResult = qLn(m_lastResult);
    else if(m_isLoging)   m_lastResult = qLn(m_lastResult)/ M_LN10;
    else if(m_isNeperexping)   m_lastResult = qPow(M_E,m_lastResult);
    m_currentNumber = 0;
    resetAllOp();

    emit displayChanged(QString::number(m_lastResult));
}
