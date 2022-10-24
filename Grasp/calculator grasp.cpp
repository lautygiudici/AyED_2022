#include <iostream>

struct Evaluator                                            
{                                           
    virtual void eval() = 0;                                            
};                                          

class Evaluate : public Evaluator
{
public:
    Evaluate(void* expression)
    {
        setExpression(*(float*)(expression));
    }
    Evaluate() {}
    void eval()                                                 
    {                                           
        result = expressionToEvaluate; 
    }                                                       
    float getResult() { return result; }
    void setExpression( void* anExpression ) { this->expressionToEvaluate = *(float*)(anExpression); }
    void setExpression( float anExpression ) { this->expressionToEvaluate = anExpression; }
private:
    float result;
    float expressionToEvaluate;
};

class Expression
{
public:
    Expression(float anExpression)
    {
        setExpression(anExpression);
    }
    void setExpression(float anExpression) { this->expression = anExpression; }
    float getExpression() { return this->expression; }
private:
    float expression;
};

class Calculator
{
public:
    Calculator(Expression* expression, Evaluate* evaluate)
    {
        evaluate->setExpression(expression->getExpression());
        evaluate->eval();
        setResult(evaluate->getResult());
        
    }
    void setResult(float result) { this->result = result; }
    float getResult() { return this->result; }
    Calculator() {}
    ~Calculator() {}
private:
    float result;
};

int main()
{
    Expression* expression = new Expression( (((3.0f * 5.0f) / 5.0f) - 1.0f) );
    Evaluate* evaluate = new Evaluate();

    Calculator calculator(expression, evaluate);
    std::cout << "show result: " << calculator.getResult() << std::endl;

    delete expression;
    delete evaluate;
    
    return 0;

}