#include <iostream>
#include <string>

int FindRandNumb(int limit)
{
    srand((unsigned)time(NULL));

    int random = rand() % limit;

    return random;
}

bool IsDigit(char c)
{
    bool isDigit = (c >= '0') && (c <= '9');

    return (isDigit);
}

bool IsNumber(std::string c)
{
    int a = c.length();

    for (int i = 0; i < a; i++)
    {
        char letter = c[i];
        bool isDigit = IsDigit(c[i]);

        if (!isDigit)
        {
            return false;
        } 
    }

    return true;
}

void ReturnResult(float a, float b, std::string c, float result)
{
    std::cout << "The result is: " << a << c << b << " = " << result << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Thank you, goodbye !" << std::endl;
}

float Calculate(float a, float b, std::string c)
{
    float result = 0;

    //char c0 = c[0];
    //switch (c0)
    //{
    //    case '+':
    //       break;
    //    case '-':
    //        break;
    //    default:
    //        break;
    //}
    if (c == "+" || c == "*" || c == "-" || c == "/")
    {
        if (c == "+")
        {
            result = a + b;
        }
        else if (c == "-") {

            result = a - b;
        }
        else if (c == "*") {

            if (a == 0 || b == 0)
            {
                std::cout << "Cannot divide by 0, sadface" << std::endl;
            }
            else {

                result = a * b;
            }

        }
        else if (c == "/") {

            result = a / b;
        }

        ReturnResult(a, b, c, result);

        return result;

    } else {

        ReturnResult(0, 0, "null", 0);
        return 0;
    }
}

float AskNumber()
{
    std::string input;

    std::cout << "Enter value (0 to 9) : " << std::endl;
    std::cin >> input;

    float val = std::stoi(input);
    
    return val;
}

std::string AskOperator()
{
    std::string input;

    std::cout << "Enter operand (+, -, *, /): " << std::endl;
    std::cin >> input;

    if (input == "+" || input == "-" || input == "*" || input == "/")
    {
        return input;

    } else {

        std::cout << "Please use one of the usable operands: +, -, *, /." << std::endl;

        return AskOperator();
    }
}

void DisplayHello()
{
    int randNumb = 0;

    randNumb = FindRandNumb(5);

    if (randNumb == 0) 
    {
        std::cout << "Hello 0" << std::endl;

    } else if (randNumb == 1) {

        std::cout << "Hello 1" << std::endl;

    } else if (randNumb == 2) {

        std::cout << "Hello 2" << std::endl;

    } else if (randNumb == 3) {

        std::cout << "Hello 3" << std::endl;

    } else if (randNumb == 4) {

        std::cout << "Hello 4" << std::endl;

    } else if (randNumb == 5) {

        std::cout << "Hello 5" << std::endl;
    }
}

void DisplayGoodbye()
{
    int randNumb = 0;

    randNumb = FindRandNumb(5);

    if (randNumb == 0)
    {
        std::cout << "Bye 0" << std::endl;

    }
    else if (randNumb == 1) {

        std::cout << "Bye 1" << std::endl;

    }
    else if (randNumb == 2) {

        std::cout << "Bye 2" << std::endl;

    }
    else if (randNumb == 3) {

        std::cout << "Bye 3" << std::endl;

    }
    else if (randNumb == 4) {

        std::cout << "Bye 4" << std::endl;

    }
    else if (randNumb == 5) {

        std::cout << "Bye 5" << std::endl;
    }
}


int main()
{
    //Welcome !
    DisplayHello();
    std::cout << "" << std::endl;

    float a = 0;
    float b = 0;
    std::string c = "null";

    float result = 0;

    a = AskNumber();

    c = AskOperator();

    b = AskNumber();

    Calculate(a, b, c);

    DisplayGoodbye();
}
