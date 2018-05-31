#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main() {
    std::string name = std::string("Cyborg");
    FragTap robot = FragTap(name);
    robot.rangedAttack("Bird");
    robot.meleeAttack("Thanos");
    robot.takeDamage(106);
    std::cout << "HP: " << robot.getHitpoints() << std::endl;
    robot.beRepaired(45);
    std::cout << "HP: " << robot.getHitpoints() << std::endl;
    robot.beRepaired(60);
    std::cout << "HP: " << robot.getHitpoints() << std::endl;
    robot.setEnergyPoints(53);
    robot.vaulthunter_dot_exe("Ennemy");
    robot.vaulthunter_dot_exe("Ennemy");
    robot.vaulthunter_dot_exe("Ennemy");
    std::cout << "Energy: " << robot.getEnergyPoints() << std::endl;


    std::cout << std::endl;
    ScavTrap robot2 = ScavTrap(name);
    robot2.rangedAttack("Bird");
    robot2.meleeAttack("Thanos");
    robot2.takeDamage(106);
    std::cout << "HP: " << robot2.getHitpoints() << std::endl;
    robot2.beRepaired(45);
    std::cout << "HP: " << robot2.getHitpoints() << std::endl;
    robot2.beRepaired(60);
    std::cout << "HP: " << robot2.getHitpoints() << std::endl;
    robot2.setEnergyPoints(53);
    robot2.challengeNewcomer();
    robot2.challengeNewcomer();
    robot2.challengeNewcomer();
    std::cout << "Energy: " << robot2.getEnergyPoints() << std::endl;


    std::cout << std::endl;
    NinjaTrap robot3 = NinjaTrap(name);
    robot3.rangedAttack("Bird");
    robot3.meleeAttack("Thanos");
    robot3.takeDamage(106);
    std::cout << "HP: " << robot3.getHitpoints() << std::endl;
    robot3.beRepaired(45);
    std::cout << "HP: " << robot3.getHitpoints() << std::endl;
    robot3.beRepaired(60);
    std::cout << "HP: " << robot3.getHitpoints() << std::endl;
    robot3.setEnergyPoints(53);
    robot3.ninjaShoebox(robot);
    robot3.ninjaShoebox(robot2);
    robot3.ninjaShoebox(robot3);
    std::cout << "Energy: " << robot3.getEnergyPoints() << std::endl;

    return 0;
}