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
    // Método para colocar números ou constantes clicados na tela EntryScreen
    void numEntered(QString);
    void constEntered(QString);

    // Método para limpar a tela
    void clear();

    // Método para limpar a tela e a memória
    void allClear();

    // Método acionado quando o botão [=] é pressionado
    void equalMode();

    // Métodos matemáticos respectivos aos botões pressionados
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
    void signalMode();

    // Método chamado ao fim de cada operação feita
    void calculate();

signals:
    void displayChanged(QString);

private:
    QString m_numAux = "";
    void setAllOp();
    void resetAllOp();
    double m_lastResult;
    double m_currentNumber;
    bool m_isEqual = false;
    bool m_isFirstTime = true;
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
    bool m_isDecimal = false;

};

#endif // CALCULATOR_H
