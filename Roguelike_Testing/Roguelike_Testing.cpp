#include "pch.h"
#include "CppUnitTest.h"
#include "../Roguelike/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RoguelikeTesting
{
	TEST_CLASS(RoguelikeTesting)
	{
	public:
		
		TEST_METHOD(PlayerMovesUp)
		{
			Player player;
			float prevYPos;
			float currentYPos;
			
			prevYPos = player.GetPosition().y; // Stores the previous position to check against later

			sf::Event _event;
			_event.type = sf::Event::KeyPressed;
			_event.key.code = sf::Keyboard::W;

			player.ProcessKeys(_event); // works as if the player hit the W key

			currentYPos = player.GetPosition().y;

			Assert::IsTrue(prevYPos > currentYPos); // Checks if pressing the button moved the player 

			prevYPos = currentYPos;
			_event.key.code = sf::Keyboard::Up; // repeat the process with the Up arrow key
			 
			player.ProcessKeys(_event);

			currentYPos = player.GetPosition().y;

			Assert::IsTrue(prevYPos > currentYPos);
		}

		TEST_METHOD(PlayerMovesDown)
		{
			Player player;
			float prevYPos;
			float currentYPos;

			prevYPos = player.GetPosition().y; // Stores the previous position to check against later

			sf::Event _event;
			_event.type = sf::Event::KeyPressed;
			_event.key.code = sf::Keyboard::S;

			player.ProcessKeys(_event); // works as if the player hit the S key

			currentYPos = player.GetPosition().y;

			Assert::IsTrue(prevYPos < currentYPos); // Checks if pressing the button moved the player 

			prevYPos = currentYPos;
			_event.key.code = sf::Keyboard::Down; // repeat the process with the Down arrow key

			player.ProcessKeys(_event);

			currentYPos = player.GetPosition().y;

			Assert::IsTrue(prevYPos < currentYPos);
		}

		TEST_METHOD(PlayerMovesLeft)
		{
			Player player;
			float prevXPos;
			float currentXPos;

			prevXPos = player.GetPosition().x; // Stores the previous position to check against later

			sf::Event _event;
			_event.type = sf::Event::KeyPressed;
			_event.key.code = sf::Keyboard::A;

			player.ProcessKeys(_event); // works as if the player hit the A key

			currentXPos = player.GetPosition().x;

			Assert::IsTrue(prevXPos > currentXPos); // Checks if pressing the button moved the player 

			prevXPos = currentXPos;
			_event.key.code = sf::Keyboard::Left; // repeat the process with the Left arrow key

			player.ProcessKeys(_event);

			currentXPos = player.GetPosition().x;

			Assert::IsTrue(prevXPos > currentXPos);
		}

		TEST_METHOD(PlayerMovesRight)
		{
			Player player;
			float prevXPos;
			float currentXPos;

			prevXPos = player.GetPosition().x; // Stores the previous position to check against later

			sf::Event _event;
			_event.type = sf::Event::KeyPressed;
			_event.key.code = sf::Keyboard::D;

			player.ProcessKeys(_event); // works as if the player hit the D key

			currentXPos = player.GetPosition().x;

			Assert::IsTrue(prevXPos < currentXPos); // Checks if pressing the button moved the player 

			prevXPos = currentXPos;
			_event.key.code = sf::Keyboard::Right; // repeat the process with the Right arrow key

			player.ProcessKeys(_event);

			currentXPos = player.GetPosition().x;

			Assert::IsTrue(prevXPos < currentXPos);
		}
	};
}
