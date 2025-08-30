
#include <iostream>
#include <limits>
#include "to_do_header_file.h"
#include <cstdlib>

void manager::emplace_task(std::string &title, std::string &description)
{
    todo_data_type new_task;
    new_task.set_title(title);
    new_task.set_description(description);
    task_vector.emplace_back(new_task);
}

void manager::erase_task(const int &id)
{
    task_vector.erase(task_vector.begin() + (id - 1));
}

void manager::mark_complete(int &id)
{
    task_vector[id - 1].set_completed();
}

void manager::mark_pending(int &id)
{
    task_vector[id - 1].set_pending();
}

bool manager::valid_size(int &id) const
{
    if (id > 0 && id <= task_vector.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void manager::print_title(int &id) const
{
    if (valid_size(id))
    {
        std::cout << task_vector[id - 1].show_title();
    }
}

void manager::print_description(int &id) const
{
    if (valid_size(id))
    {
        std::cout << task_vector[id - 1].show_description();
    }
}

void console::add_a_task()
{
    std::string title, description;
    std::cout << "Enter the title of the task: ";
    std::getline(std::cin, title);
    std::cout << "Enter the description of the task: ";
    std::getline(std::cin, description);
    todo_list.emplace_task(title, description);
}

void console::remove_a_task()
{
    int id;
    std::cout << "Enter the ID number of the Task you want to delete\n";
    std::cin >> id;
    if (todo_list.valid_size(id) == true)
    {
        std::cout << "The Task with Title: ";
        todo_list.print_title(id);
        std::cout << " Will be DELETED!!!\n";
        std::cout << "Enter 'y' to delete or any 'other key' to say 'DONT DELETE'\n";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            todo_list.erase_task(id);
        }
    }
    else
    {
        std::cout << "You Entered a wrong ID!!\n";
    }
}

void console::set_as_complete()
{
    std::cout << "Enter the Task ID of task to be Completed\n";
    int id;
    std::cin >> id;
    if (todo_list.valid_size(id))
    {
        std::cout << "The Title of task you want to set as complete\nTitle: ";
        todo_list.print_title(id);
        todo_list.mark_complete(id);
    }
    else
    {
        std::cout << "You Entered a wrong ID!!\n";
    }
}

void console::set_as_pending()
{
    std::cout << "Enter the Task ID of task to be Set as Pending\n";
    int id;
    std::cin >> id;
    if (todo_list.valid_size(id))
    {
        std::cout << "The Title of task you want to set as Pending\nTitle: ";
        todo_list.print_title(id);
        todo_list.mark_pending(id);
    }
    else
    {
        std::cout << "You Entered a wrong ID!!\n";
    }
}

void console::start_console()
{
    while (true)
    {
        std::cout << "Enter 1 to Add a Task\n";
        std::cout << "Enter 2 to Remove a Task\n";
        std::cout << "Enter 3 to Mark to see specific task\n";
        std::cout << "Enter 4 to Mark a Task as Complete\n";
        std::cout << "Enter 5 to Mark a Task as Pending\n";
        std::cout << "Enter 6 to Print all Tasks\n";
        std::cout << "Enter 7 to Print Pending Tasks\n";
        std::cout << "Enter 8 to Exit the Program\n";

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            add_a_task();
            break;
        case 2:
            remove_a_task();
            break;
        case 3:
            set_as_complete();
            break;
        case 4:
            set_as_pending();
            //     break;
            // case 5:
            //     todo_list.print_all_tasks();
            //     break;
            // case 6:
            //     todo_list.print_pending_tasks();
            break;
        case 7:
            std::cout << "Exiting the program. Goodbye!\n";
            return;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            break;
        }
    }
}