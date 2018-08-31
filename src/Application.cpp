#include "Application.h"

int Application::getEncryptionChoice() {
	int choice = 0;
	print("Which cipher do you want now ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, 1, 7)) {
		return choice;
	}
	return 0;
}

int Application::getMainMenuChoice() {
	int choice = 0;
	print("What are you about to do ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, 1, 3)) {
		return choice;
	}
	return 0;
}

int Application::getInputChoice() {
	int choice = 0;
	print("How can I get the input ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, 1, 2)) {
		return choice;
	}
	return 0;
}

void Application::showEncryptionOptions() {
	println("Types of ciphers available : ");
	println("1 > Bitwise");
	println("2 > Block");
	println("3 > Caesar");
	println("4 > Stream");
	println("5 > Transpose");
	println("6 > Vigenere");
	println("7 > Xor (Exclusive OR)");
}

void Application::showMainMenu() {
	println("What to do now ?");
	println("1 > Encryption");
	println("2 > Decryption");
	println("3 > Exit");
}

void Application::showInputOptions() {
	println("How are you going to enter the information ?");
	println("1 > Type it now");
	println("2 > Retrieve it from a existing file");
}

void Application::manageEncryption() {
	showEncryptionOptions();
	int encryptionChoice = getEncryptionChoice();
	while (encryptionChoice == 0) {
		printNextLine();
		println("Try to choose an available cipher option.");
		printNextLine();
		showEncryptionOptions();
		encryptionChoice = getEncryptionChoice();
	}
}

void Application::manageDecryption() {
	// TODO: Implement this method
	println("Yet to be implemented!!!");
}

void Application::showEndCredits() {
	clearScreen();
	std::string title = "Project done by the following students of XII - A :";
	std::string decoration(title.size(), '~');
	printHeading(title, decoration);
	printLines(3);
	printcnt("Abhishek Sriram, Roll No : 2");
	printcnt("Ashwin Kumar M, Roll No : 3");
	printcnt("Prajeen R G, Roll No : 20");
	printcnt("Vishal B, Roll No : 40");
	printLines(3);
}

void Application::runApp() {
	showMainMenu();
	int menuChoice = getMainMenuChoice();
	while (menuChoice == 0) {
		printNextLine();
		println("Try to follow the given instructions.");
		printNextLine();
		showMainMenu();
		menuChoice = getMainMenuChoice();
	}
	printNextLine();
	switch (menuChoice) {
		case 1:
			manageEncryption();
			break;
		case 2:
			manageDecryption();
			break;
		default:
			showEndCredits();
			return;
	}
	showEndCredits();
}