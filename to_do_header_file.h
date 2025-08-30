#pragma once
#include <vector>
#include <string>

class todo_data_type
{
    std::string title{"No title Given"};
    std::string description{"No description Given"};
    bool completed{false};

public:
    void set_title(const std::string &t) { title = t; }
    void set_description(const std::string &d) { description = d; }

    bool is_completed() const { return completed; }
    void set_completed() { completed = true; }
    void set_pending() { completed = false; }
    std::string show_title() const { return title; }
    std::string show_description() const { return description; }
};
class manager
{

    std::vector<todo_data_type> task_vector;

public:
    void emplace_task(std::string &title, std::string &description);
    void erase_task(const int &id);
    void mark_complete(int &id);
    void mark_pending(int &id);

    void print_pending_tasks() const;
    void print_all_tasks() const;

    bool valid_size(int &id) const;
    void print_title(int &id) const;
    void print_description(int &id) const;
    void set_new_title(int &id);
    void set_new_tile(int &id);
};

class console
{
    manager todo_list;

public:
    void start_console();

    void add_a_task();
    void remove_a_task();
    void set_as_complete();
    void set_as_pending();
};