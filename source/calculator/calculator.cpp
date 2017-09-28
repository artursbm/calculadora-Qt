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
{}

// Método chamado dentro de Calculator::clear() ou Calculator::equalMode();
// Todos os verificadores de operação são setados para 'true'.
void Calculator::setAllOp() {
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

// Método chamado ao fim de Calculator::calculate(), ou seja,
// após o término da operação realizada, todos os verificadores
// de operação são setados para 'false', resetando as operações.
void Calculator::resetAllOp() {
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

// Função que transforma o valor do botão numérico ou de constante
// pressionado na calculadora para um valor que será mostrado
// corretamente na EntryScreen.
void Calculator::numEntered(QString num) {

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

// Método acionado quando o botão [+/-] é pressionado
// mudando o sinal do operador atual mostrado na tela.
void Calculator::signalMode() {
    m_currentNumber = -m_currentNumber;
    emit displayChanged(QString::number(m_currentNumber));
}

//void Calculator::constEntered(QString num)
//{
//    m_numAux = "";
//    m_currentNumber = num.toFloat();
//    emit displayChanged(QString::number(m_currentNumber,'f',10));
//}

// Método chamado ao se pressionar o botão [CLEAR]
// irá limpar a tela, mas manterá o último resultado na
// memória.
void Calculator::clear() {
    m_currentNumber = 0;
    setAllOp();
    emit displayChanged(QString::number(m_currentNumber));
}

// Método chamado ao se pressionar o botão [AC];
// limpa a tela e a memória, zerando inclusive o último
// resultado armazenado.
void Calculator::allClear() {
    m_currentNumber = 0;
    m_lastResult = 0;
    setAllOp();
    emit displayChanged(QString::number(m_currentNumber));

}

// Método chamado ao se pressionar o botão [=];
// Chama Calculator::calculate(), que realiza a operação
// requerida pelo botão de operação requerido.
void Calculator::equalMode() {
    calculate();
    setAllOp();
    m_currentNumber = 0;
    m_lastResult = 0;
}

// Método que ativa o modo de adição de dois operadores,
// após pressioar o botão [+]
void Calculator::additionMode() {
    calculate();
    m_isAdding = true;
}

// Método que ativa o modo de subtração de dois operadores,
// após pressioar o botão [-]
void Calculator::subtractionMode() {
    calculate();
    m_isSubtracting = true;
}

// Método que ativa o modo de multiplicação de dois operadores,
// após pressioar o botão [x]
void Calculator::multiplicationMode() {
    calculate();
    m_isMultiplying = true;
}

// Método que ativa o modo de divisão de dois operadores,
// após pressioar o botão [:]
void Calculator::divisionMode() {
    calculate();
    m_isDividing = true;
}

// Método que ativa o modo de raiz quadrada do operador,
// após pressioar o botão [sqrt]
void Calculator::sqrtMode() {
    calculate();
    m_isSqrting = true;
}

// Método que ativa o modo potência de 2 do operador,
// após pressioar o botão [x²]
void Calculator::squareMode() {
    calculate();
    m_isSquaring = true;
}

// Método que ativa o modo potência de 3 do operador,
// após pressioar o botão [x³]
void Calculator::cubeMode() {
    calculate();
    m_isCubing = true;
}

// Método que ativa o modo exponencial de dois operadores,
// após pressioar o botão [x^y]
void Calculator::exponentMode() {
    calculate();
    m_isExponenting = true;
}

// Método que ativa o modo de seno de um número em rad,
// após pressioar o botão [sin(x)]
void Calculator::sinMode() {
    calculate();
    m_isSining = true;
}

// Método que ativa o modo de cosseno de um número em rad,
// após pressioar o botão [cos(x)]
void Calculator::cosMode() {
    calculate();
    m_isCosing = true;
}

// Método que ativa o modo de tangente de um número em rad,
// após pressioar o botão [tg(x)]
void Calculator::tgMode() {
    calculate();
    m_isTangenting = true;
}

// Método que ativa o modo logaritmo neperiano do operador,
// após pressioar o botão [ln(x)]
void Calculator::neperlogMode() {
    calculate();
    m_isNeperloging = true;
}

// Método que ativa o modo logaritmo na base 10 do operador,
// após pressioar o botão [log(x)]
void Calculator::logMode() {
    calculate();
    m_isLoging = true;
}

// Método que ativa o modo exp do operador,
// após pressioar o botão [e^x]
void Calculator::neperexpMode() {
    calculate();
    m_isNeperexping = true;
}

// Método chamado para realizar a operação ativada por
// um dos métodos implementados acima. Testa a condição para
// saber qual operação deve ser realizada, e coloca o resultado
// em uma variável de memória (m_lastResult).
// Após os cálculos realizados, se o botão [=] for pressionado,
// a memória é limpa, indicando um "recomeço" do programa.
void Calculator::calculate() {
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
