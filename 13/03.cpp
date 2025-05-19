#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

struct Process {
    std::string name;
    int pid;
    std::string status;
    std::string owner;
};

std::vector<Process> generateProcesses() {
    return {
        {"systemd", 1, "running", "root"},
        {"bash", 1024, "sleeping", "user1"},
        {"chrome", 2048, "running", "user1"},
        {"python", 3072, "waiting", "user2"},
        {"vim", 5120, "sleeping", "user1"},
        {"ssh", 6144, "running", "user2"},
        {"docker", 7168, "sleeping", "root"},
    };
}

void printProcessTable(const std::vector<Process>& processes) {
    std::cout << std::left 
              << std::setw(20) << "Process Name"
              << std::setw(10) << "PID"
              << std::setw(15) << "Status"
              << std::setw(15) << "Owner" << std::endl;
    
    std::cout << std::setfill('-') << std::setw(60) << "" << std::endl;
    std::cout << std::setfill(' ');
    
    for (const auto& proc : processes) {
        std::cout << std::left
                  << std::setw(20) << proc.name
                  << std::setw(10) << proc.pid
                  << std::setw(15) << proc.status
                  << std::setw(15) << proc.owner << std::endl;
    }
}

int main() {
    auto processes = generateProcesses();
    printProcessTable(processes);
    
    return 0;
}
