#include <vector>
#include <string>
#include <iostream>

#include "solution.h"

// Text used in the Yandex.Contest platform to evaluate your submissions
const std::string TEXT =
R"(The Cat only grinned when it saw Alice. 
It looked good-natured, she thought: still it had very long claws and a great many teeth, so she felt that it ought to be treated with respect.
Cheshire Puss, she began, rather timidly, as she did not at all know whether it would like the name: however, it only grinned a little wider.
Come, it's pleased so far, thought Alice, and she went on. Would you tell me, please, which way I ought to go from here?.
That depends a good deal on where you want to get to, said the Cat.
I don't much care where — said Alice. Then it doesn't matter which way you go, said the Cat.
— so long as I get somewhere, Alice added as an explanation.
Oh, you're sure to do that, said the Cat, if you only walk long enough.
Alice felt that this could not be denied, so she tried another question. What sort of people live about here?
In that direction, the Cat said, waving its right paw round, lives a Hatter: and in that direction, waving the other paw, lives a March Hare.
Visit either you like: they're both mad.
But I don't want to go among mad people, Alice remarked.
Oh, you can't help that, said the Cat: we're all mad here. I'm mad. You're mad.
How do you know I'm mad? said Alice. You must be, said the Cat, or you wouldn't have come here.
Alice didn't think that proved it at all; however, she went on And how do you know that you're mad?
To begin with, said the Cat, a dog's not mad. You grant that?
I suppose so, said Alice.
Well, then, the Cat went on, you see, a dog growls when it's angry, and wags its tail when it's pleased.
Now I growl when I'm pleased, and wag my tail when I'm angry. Therefore I'm mad.
I call it purring, not growling, said Alice.
Call it what you like, said the Cat. Do you play croquet with the Queen to-day?
I should like it very much, said Alice, but I haven't been invited yet.
You'll see me there, said the Cat, and vanished.
Alice was not much surprised at this, she was getting so used to queer things happening.
While she was looking at the place where it had been, it suddenly appeared again.
By-the-bye, what became of the baby? said the Cat. I'd nearly forgotten to ask.
It turned into a pig, Alice quietly said, just as if it had come back in a natural way.
I thought it would, said the Cat, and vanished again.)";


// Test #1: Evaluates the constructor, next(), hasNext() and count() functions
void test1()
{
	std::string pattern = "Alice";

	StringFinder stringFinder(TEXT, pattern);

	while (stringFinder.hasNext())
	{
		auto [line, index] = stringFinder.next();

		std::cout << line << ' ' << index << std::endl;
	}

	std::cout << stringFinder.count() << std::endl;
}

// Test #2: Evaluates printLines() function
void test2()
{
	std::string pattern = "mad";

	StringFinder stringFinder(TEXT, pattern);

	stringFinder.printLines();
}

// Test #3: Evaluates last(), hasPrevious(), and previous()
void test3()
{
	std::string pattern = "Cat";

	StringFinder stringFinder(TEXT, pattern);

	stringFinder.last();

	while (stringFinder.hasPrevious())
	{
		auto [line, index] = stringFinder.previous();

		std::cout << line << ' ' << index << std::endl;
	}
}

// Text #4: Evaluates the constructor with case sensitive option
void test4()
{
	std::string pattern = "SaiD THE caT";

	const bool CASE_SENSITIVE = false;

	StringFinder stringFinder(TEXT, pattern, CASE_SENSITIVE);

	while (stringFinder.hasNext())
	{
		auto [line, index] = stringFinder.next();

		std::cout << line << ' ' << index << std::endl;
	}

	std::cout << stringFinder.count() << std::endl;
}


int main()
{
	test1();

	//test2();

	//test3();

	//test4();

	return 0;
}