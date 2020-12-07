#include <iostream>

void FizzBuzz(int num)
{
	for (int i = 0; i < num; i++)
	{
		std::cout << i;
		if (i % 15 == 0)
			std::cout << " FizzBuzz" << std::endl;
		else if (i % 5 == 0)
			std::cout << " Buzz" << std::endl;
		else if (i % 3 == 0)
			std::cout << " Fizz" << std::endl;
		else
			std::cout << " Not multiple of 3 or 5" << std::endl;
	}
}
int main()
{
	bool loop = true;
	int num = 0;
	while (loop == true)
	{
		std::cout << "Please Enter A Max Number: ";
		std::cin >> num;
		FizzBuzz(num);
	}
	system("pause");
	return 1;
}