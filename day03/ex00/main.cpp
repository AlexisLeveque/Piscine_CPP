#include <iostream>
#include "FragTrap.hpp"

int main() {
    std::string name = std::string("Cyborg");
    FragTap robot = FragTap(name);
    robot.rangedAttack("Bird");
    robot.meleeAttack("Lich King");
    robot.takeDamage(106);
    std::cout <<  "HP: " << robot.getHitpoints() << std::endl;
    robot.beRepaired(45);
    std::cout <<  "HP: " << robot.getHitpoints() << std::endl;
    robot.beRepaired(60);
    std::cout << "HP: " <<  robot.getHitpoints() << std::endl;
    robot.setEnergyPoints(53);
    robot.vaulthunter_dot_exe("Ennemy");
    robot.vaulthunter_dot_exe("Ennemy");
    robot.vaulthunter_dot_exe("Ennemy");
    std::cout << "Energy: " << robot.getEnergyPoints() << std::endl;

    return 0;
}