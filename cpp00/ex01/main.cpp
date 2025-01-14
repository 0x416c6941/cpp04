#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <defs.hpp>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstddef>
#include <iomanip>

/**
 * Asks user for the command (may be ADD, SEARCH or EXIT).
 * @throws  std::ios_base::failure  If an IO error occurs.
 * @throws  std::runtime_error      Got EOF.
 * @return  Command entered by the user.
 */
t_command get_command() {
    std::string in;

    for (;;) {
        std::cout << "Please enter ADD, SEARCH or EXIT: ";
        std::cin >> in;
        if (std::cin.fail() && !std::cin.eof()) {
            throw std::ios_base::failure("get_command():: IO error.");
        }
        else if (std::cin.eof()) {
            throw std::runtime_error("get_command():: Got EOF.");
        }
        else if (in.compare("ADD") == 0) {
            return ADD;
        }
        else if (in.compare("SEARCH") == 0) {
            return SEARCH;
        }
        else if (in.compare("EXIT") == 0) {
            return EXIT;
        }
        std::cout << "Invalid command. Please try again." << std::endl << std::endl;
    }
}

/**
 * Adds a new contact to the phone book with the data entered by the user.
 * This function can be shortened by using e.g. enums.
 * @param   pb                      Phone book to which the contact
 *                                  will be added.
 * @throws  std::ios_base::failure  If an IO error occurs.
 * @throws  std::runtime_error      Got EOF.
 */
void add_contact(PhoneBook & pb) {
    std::string in;
    const std::string io_exception_msg = "add_contact():: IO error.";
    const std::string eof_msg = "add_contact():: Got EOF.";
    Contact to_add;

    std::cin.ignore();  // Flushing the buffer.
    std::cout << "Please enter a name of the new contact: ";
    std::getline(std::cin, in);
    if (std::cin.fail() && !std::cin.eof()) {
        throw std::ios_base::failure(io_exception_msg);
    }
    else if (std::cin.eof()) {
        throw std::runtime_error(eof_msg);
    }
    to_add.set_name(in);
    std::cout << "Please enter a last name of the new contact: ";
    std::getline(std::cin, in);
    if (std::cin.fail() && !std::cin.eof()) {
        throw std::ios_base::failure(io_exception_msg);
    }
    else if (std::cin.eof()) {
        throw std::runtime_error(eof_msg);
    }
    to_add.set_last_name(in);
    std::cout << "Please enter a nickname of the new contact: ";
    std::getline(std::cin, in);
    if (std::cin.fail() && !std::cin.eof()) {
        throw std::ios_base::failure(io_exception_msg);
    }
    else if (std::cin.eof()) {
        throw std::runtime_error(eof_msg);
    }
    to_add.set_nickname(in);
    for (;;) {
        std::cout << "Please enter a phone number of the new contact: ";
        std::getline(std::cin, in);
        if (std::cin.fail() && !std::cin.eof()) {
            throw std::ios_base::failure(io_exception_msg);
        }
        else if (std::cin.eof()) {
            throw std::runtime_error(eof_msg);
        }
        try {
            to_add.set_phone(in);
        }
        catch (std::invalid_argument & e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
        break;
    }
    std::cout << "Please enter a secret of the new contact: ";
    std::getline(std::cin, in);
    if (std::cin.fail() && !std::cin.eof()) {
        throw std::ios_base::failure(io_exception_msg);
    }
    else if (std::cin.eof()) {
        throw std::runtime_error(eof_msg);
    }
    to_add.set_secret(in);
    try {
        pb.add_contact(to_add);
    }
    catch (std::invalid_argument & e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Displays a string as a part of a column with a specified width.
 * @param   what            String to be displayed.
 * @param   column_width    Width of the column.
 */
void display_in_column(const std::string & what, size_t column_width) {
    if (what.size() < column_width) {
        std::cout << std::setw(column_width) << std::setfill(' ')
                  << std::right << what;
        return;
    }
    std::cout << what.substr(0, column_width - 1) << '.';
}

/**
 * Displays all contacts in the phone book.
 * @param   pb              Phone book to be displayed.
 * @param   column_width    Width of the column in which the data
 *                          will be displayed.
 */
void display_contacts(PhoneBook & pb, size_t column_width = 10) {
    std::stringstream ss;
    std::string idx;

    for (std::size_t i = 0; i < pb.get_contacts_cnt(); i++) {
        ss.str(""); // Clearing the stream.
        ss << i + 1;
        idx = ss.str();
        display_in_column(idx, column_width);
        std::cout << '|';
        display_in_column(pb.get_contact(i).get_name(), column_width);
        std::cout << '|';
        display_in_column(pb.get_contact(i).get_last_name(), column_width);
        std::cout << '|';
        display_in_column(pb.get_contact(i).get_nickname(), column_width);
        std::cout << std::endl;
    }
}

/**
 * Asks user for an index of a contact to display and displays it.
 * @param   pb                      Phone book from which the contact
 *                                  will be displayed.
 * @param   column_width            Width of the column in which the data
 *                                  will be displayed.
 * @throws  std::ios_base::failure  If an IO error occurs.
 * @throws  std::runtime_error      Got EOF.
 */
void display_specific_contact(PhoneBook & pb, size_t column_width = 10) {
    std::size_t idx;
    Contact to_display;

    std::cout << "Which contact to display: ";
    std::cin >> idx;
    if (std::cin.fail() && !std::cin.eof()) {
        throw std::ios_base::failure("display_specific_contact():: IO error.");
    }
    else if (std::cin.eof()) {
        throw std::runtime_error("display_specific_contact():: Got EOF.");
    }
    try {
        to_display = pb.get_contact(idx - 1);
    }
    catch (std::out_of_range & e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    display_in_column(to_display.get_name(), column_width);
    std::cout << '|';
    display_in_column(to_display.get_last_name(), column_width);
    std::cout << '|';
    display_in_column(to_display.get_nickname(), column_width);
    std::cout << '|';
    display_in_column(to_display.get_phone(), column_width);
    std::cout << '|';
    display_in_column(to_display.get_secret(), column_width);
    std::cout << std::endl;
}

int main() {
    t_command user_command;
    PhoneBook pb;

    for (;;) {
        try {
            user_command = get_command();
        }
        catch (std::ios_base::failure & e) {
            std::cerr << e.what() << std::endl;
            return IO_FAIL;
        }
        catch (std::runtime_error & e) {
            std::cout << std::endl;
            return 0;
        }
        switch (user_command) {
            case ADD:
                try {
                    add_contact(pb);
                }
                catch (std::ios_base::failure & e) {
                    std::cerr << e.what() << std::endl;
                    return IO_FAIL;
                }
                catch (std::runtime_error & e) {
                    std::cout << std::endl;
                    return 0;
                }
                break;
            case SEARCH:
                display_contacts(pb);
                if (pb.get_contacts_cnt() == 0) {
                    break;
                }
                std::cout << std::endl;
                try {
                    display_specific_contact(pb);
                }
                catch (std::ios_base::failure & e) {
                    std::cerr << e.what() << std::endl;
                    return IO_FAIL;
                }
                catch (std::runtime_error & e) {
                    std::cout << std::endl;
                    return 0;
                }
                break;
            case EXIT:
                return 0;
        }
        std::cout << std::endl;
    }
}
