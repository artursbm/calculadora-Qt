#include "calculatorinterface.h"
#include "ui_calculatorinterface.h"

#include <QSignalMapper>
#include "calculator.h"

CalculatorInterface::CalculatorInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorInterface),
    m_calculator(new Calculator(this))
{
    ui->setupUi(this);

    QSignalMapper *m = new QSignalMapper(this);
    QSignalMapper *c = new QSignalMapper(this);
// --------- Setup de botões numéricos no modo normal ---------- //
    // Conectando os botões de números do modo normal:
    // map de número pressionado para inteiro.
    connect(ui->buttonZero,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonZero,QString::number(0));


    connect(ui->buttonOne,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonOne,QString::number(1));


    connect(ui->buttonTwo,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonTwo,QString::number(2));


    connect(ui->buttonThree,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonThree,QString::number(3));


    connect(ui->buttonFour,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonFour,QString::number(4));

    connect(ui->buttonFive,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonFive,QString::number(5));


    connect(ui->buttonSix,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonSix,QString::number(6));


    connect(ui->buttonSeven,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonSeven,QString::number(7));


    connect(ui->buttonEight,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonEight,QString::number(8));


    connect(ui->buttonNine,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonNine,QString::number(9));
// -------------------------------------------------------------- //

// -------- Setup de botões numéricos no modo científico -------- //
    // conectando os botões do modo científico:
    // map de número pressionado para inteiro.
    connect(ui->buttonZero_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonZero_2,QString::number(0));


    connect(ui->buttonOne_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonOne_2,QString::number(1));


    connect(ui->buttonTwo_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonTwo_2,QString::number(2));


    connect(ui->buttonThree_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonThree_2,QString::number(3));


    connect(ui->buttonFour_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonFour_2,QString::number(4));

    connect(ui->buttonFive_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonFive_2,QString::number(5));


    connect(ui->buttonSix_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonSix_2,QString::number(6));


    connect(ui->buttonSeven_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonSeven_2,QString::number(7));


    connect(ui->buttonEight_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonEight_2,QString::number(8));


    connect(ui->buttonNine_2,SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonNine_2,QString::number(9));

    connect(ui->buttonPi,SIGNAL(clicked()), c,SLOT(map()));
    c->setMapping(ui->buttonPi,QString::number(M_PI));

    connect(ui->buttonNeper,SIGNAL(clicked()), c,SLOT(map()));
    c->setMapping(ui->buttonNeper,QString::number(M_E));

// ----------------------------------------------------------------- //

    // conectando o botão [.] de decimal
    connect(ui->buttonDecimal, SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonDecimal,".");

    connect(ui->buttonDecimal_2, SIGNAL(clicked()), m,SLOT(map()));
    m->setMapping(ui->buttonDecimal_2,".");



    // botão de Sinal negativo em ambos os modos:
    connect(ui->buttonSignal, SIGNAL(clicked()),
        m_calculator, SLOT(signalMode()));
    connect(ui->buttonSignal_2, SIGNAL(clicked()),
        m_calculator, SLOT(signalMode()));


    // Adição e Subtração em ambos os modos:
    connect(ui->buttonAdd, SIGNAL(clicked()),
        m_calculator, SLOT(additionMode()));
    connect(ui->buttonSubtract, SIGNAL(clicked()),
        m_calculator, SLOT(subtractionMode()));

    connect(ui->buttonAdd_2, SIGNAL(clicked()),
        m_calculator, SLOT(additionMode()));
    connect(ui->buttonSubtract_2, SIGNAL(clicked()),
        m_calculator, SLOT(subtractionMode()));

    // Multiplicação e Divisão em ambos os modos:
    connect(ui->buttonMultiply, SIGNAL(clicked()),
        m_calculator, SLOT(multiplicationMode()));
    connect(ui->buttonDivide, SIGNAL(clicked()),
        m_calculator, SLOT(divisionMode()));

    connect(ui->buttonMultiply_2, SIGNAL(clicked()),
        m_calculator, SLOT(multiplicationMode()));
    connect(ui->buttonDivide_2, SIGNAL(clicked()),
        m_calculator, SLOT(divisionMode()));

    //Funções do modo científico:
    connect(ui->buttonSqrt, SIGNAL(clicked()),
        m_calculator, SLOT(sqrtMode()));

    connect(ui->buttonSqr, SIGNAL(clicked()),
        m_calculator, SLOT(squareMode()));

    connect(ui->buttonCube, SIGNAL(clicked()),
        m_calculator, SLOT(cubeMode()));

    connect(ui->buttonExp, SIGNAL(clicked()),
        m_calculator, SLOT(exponentMode()));

    connect(ui->buttonSin, SIGNAL(clicked()),
        m_calculator, SLOT(sinMode()));

    connect(ui->buttonCos, SIGNAL(clicked()),
        m_calculator, SLOT(cosMode()));

    connect(ui->buttonTg, SIGNAL(clicked()),
        m_calculator, SLOT(tgMode()));

    connect(ui->buttonLn, SIGNAL(clicked()),
        m_calculator, SLOT(neperlogMode()));

    connect(ui->buttonLog, SIGNAL(clicked()),
        m_calculator, SLOT(logMode()));

    connect(ui->buttonNeperexp, SIGNAL(clicked()),
        m_calculator, SLOT(neperexpMode()));

    // CALCULATE
    connect(ui->buttonCalculate, SIGNAL(clicked()),
        m_calculator, SLOT(equalMode()));
    connect(ui->buttonCalculate_2, SIGNAL(clicked()),
        m_calculator, SLOT(equalMode()));


    // map de numero para numero digitado, e deste para a entryScreen
    connect(m, SIGNAL(mapped(QString)), m_calculator, SLOT(numEntered(QString)));
    connect(c, SIGNAL(mapped(const QString)), m_calculator, SLOT(constEntered(QString)));
    connect(m_calculator, SIGNAL(displayChanged(QString)),
        ui->entryScreen, SLOT(setText(QString)));

    // clear da tela e allClear em ambos os modos
    connect(ui->buttonClear, SIGNAL(clicked()), m_calculator, SLOT(clear()));
    connect(ui->buttonAllClear, SIGNAL(clicked()),
        m_calculator, SLOT(allClear()));

    connect(ui->buttonClear_2, SIGNAL(clicked()), m_calculator, SLOT(clear()));
    connect(ui->buttonAllClear_2, SIGNAL(clicked()),
        m_calculator, SLOT(allClear()));
}

CalculatorInterface::~CalculatorInterface()
{
    delete ui;
}

void CalculatorInterface::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
