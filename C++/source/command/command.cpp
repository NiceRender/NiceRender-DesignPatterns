#include <iostream>
#include <vector>

// Receiver
class Calculator
{
    public:
        void add(double val) { m_result += val; this->printResult(); }
        void sub(double val) { m_result -= val; this->printResult(); }
        void printResult() { std::cout << "Result: " << m_result << "\n"; }
        
    private:
        double m_result = 0.0;
};

// Command
class CalculatorCommand
{
    public:
       virtual ~CalculatorCommand();
       virtual void execute() = 0; 
       virtual void unExecute() = 0; 
       void setCalculator(Calculator* calculator) { m_calculator = calculator; }
       
    protected:
       Calculator* m_calculator;
}; 

CalculatorCommand::~CalculatorCommand() {}

// Concrete command
class AddCommand : public CalculatorCommand
{
    public:
        AddCommand(double val) : m_val(val) {}
        void execute();
        void unExecute();
    
    private:
        double m_val;
};

void AddCommand::execute() { m_calculator->add(m_val); }
void AddCommand::unExecute() { m_calculator->sub(m_val); }

// Concrete command
class SubCommand : public CalculatorCommand
{
    public:
        SubCommand(double val) : m_val(val) {}
        void execute();
        void unExecute();
    
    private:
        double m_val;
};

void SubCommand::execute() { m_calculator->sub(m_val); }
void SubCommand::unExecute() { m_calculator->add(m_val); }

// Invoker
class CalculatorInvoker
{
    public:
        void doCommand(CalculatorCommand* command)
        {
            if (m_cmdIndex != m_doneCommands.size() - 1)
                m_doneCommands.resize(m_cmdIndex + 1);
        
            command->setCalculator(&m_calculator);
            command->execute();
            m_doneCommands.push_back(command);
            m_cmdIndex = m_doneCommands.size() - 1;
        }
        
        void undo()
        {
            if (m_cmdIndex == 0)
            {
                std::cout << "There is nothing to undo!" << std::endl;
                return;
            }
        
            m_doneCommands[m_cmdIndex]->unExecute();
            m_cmdIndex--;
        }
        
        void redo()
        {
            if (m_cmdIndex == m_doneCommands.size() - 1)
            {
                std::cout << "There is nothing to redo!" << std::endl;
                return;
            }
        
            m_cmdIndex++;
            m_doneCommands[m_cmdIndex]->execute();
        }
        
    private:
        Calculator m_calculator;
        std::vector<CalculatorCommand*> m_doneCommands;
        ulong m_cmdIndex = 0;
};

int main()
{
    CalculatorInvoker calculator;
    
    calculator.doCommand(new AddCommand(1));
    calculator.doCommand(new AddCommand(1));
    calculator.doCommand(new AddCommand(1));
    calculator.undo();
    calculator.undo();
    calculator.undo();
    calculator.undo();
    calculator.redo();
    calculator.redo();
    calculator.doCommand(new AddCommand(2));
    calculator.redo();
}
