#include <iostream>

struct IExpression
{
    virtual void setExpression( std::string anExpression ) = 0;
    virtual std::string getExpression() = 0;
};
struct IEvaluator
{
    virtual void eval( IExpression* expression ) = 0;
    virtual void* result() = 0;
};                 

class Expression : public IExpression
{
public:
    Expression( std::string anExpression ) { setExpression( anExpression ); }
    
    /* setters and getters... */
    void        setExpression( std::string anExpression ) { this->expression = anExpression; }
    std::string getExpression() { return this->expression; }
private:
    std::string expression;
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
        temporalResult = expressionToEvaluate; 
    }                                  
    void* result(float anTemporalResult)
    {
        return *(void*)(temporalResult);
    }                     
    float gettemporalResult() { return temporalResult; }
    void setExpression( void* anExpression ) { this->expressionToEvaluate = *(float*)(anExpression); }
    void setExpression( float anExpression ) { this->expressionToEvaluate = anExpression; }
private:
    float result;
    float expressionToEvaluate;
};

class Calculator
{
public:
    Calculator(Expression expression, Evaluate evaluate)
    {
        evaluate.setExpression(expression.getExpression());
        evaluate.eval();
        setResult(evaluate.getResult());
        
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
    Calculator calculator(Expression(((3.0f * 5.0f) / 5.0f - 1.0f)), Evaluate());
    std::cout << "show result: " << calculator.getResult() << std::endl;
     
    return 0;
}
   