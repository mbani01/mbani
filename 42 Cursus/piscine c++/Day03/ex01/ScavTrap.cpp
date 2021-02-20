/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:40:58 by mbani             #+#    #+#             */
/*   Updated: 2021/02/07 18:23:11 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout<<"Hey! You're TALKING to me! And I didn't even have an exclamation point over my head! This is the BEST day of my life!"<<std::endl;
	Hitpoints = 100;
	Maxhitpoints = 100;
	Energypoints = 50;
	Maxenergypoints = 50;
	Level = 1;
	Name = name;
	Meleeattackdamage = 20;
	Rangedattackdamage = 15;
	Armordamagereduction = 3;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	Hitpoints = obj.Hitpoints;
	Maxhitpoints = obj.Maxhitpoints;
	Energypoints = obj.Energypoints;
	Maxenergypoints = obj.Maxenergypoints;
	Level = obj.Level;
	Name = obj.Name;
	Meleeattackdamage = obj.Meleeattackdamage;
	Rangedattackdamage = obj.Rangedattackdamage;
	Armordamagereduction = obj.Armordamagereduction;	
}

void ScavTrap::operator=(const ScavTrap & obj)
{
	Hitpoints = obj.Hitpoints;
	Maxhitpoints = obj.Maxhitpoints;
	Energypoints = obj.Energypoints;
	Maxenergypoints = obj.Maxenergypoints;
	Level = obj.Level;
	Name = obj.Name;
	Meleeattackdamage = obj.Meleeattackdamage;
	Rangedattackdamage = obj.Rangedattackdamage;
	Armordamagereduction = obj.Armordamagereduction;	
}

ScavTrap::~ScavTrap()
{
	std::cout<<"Nonono, you're not dead, you're ...!"<<std::endl;
}
void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout<<"Sc4v-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Rangedattackdamage<<" points of damage!"<<std::endl;
}
void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout<<"Sc4v-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Meleeattackdamage<<" points of damage!"<<std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
{
	if((Hitpoints - (int)amount) + Armordamagereduction < 0)
		Hitpoints = 0;
	else if ((Hitpoints - (int)amount) + Armordamagereduction > 100)
		Hitpoints = 100;
	else
		Hitpoints = Hitpoints - (int)amount + Armordamagereduction;
	std::cout<<"\033[1;31mYou are damaged :( !\033[0m HP:"<<Hitpoints<<std::endl;
}
void ScavTrap::beRepaired(unsigned int amount)
{
	if((int)(amount) + Hitpoints > Maxhitpoints)
		Hitpoints = Maxhitpoints;
	else
		Hitpoints += (int)amount;
	if((int)(amount) + Energypoints > Maxenergypoints)
		Energypoints = Maxenergypoints;
	else
		Energypoints += amount;
	std::cout<<"\033[1;32mYou are Repaired :) !\033[0m HP:"<<Hitpoints<<" Energypoints :"<<Energypoints<<std::endl;
}
void ScavTrap::challengeNewcomer(std::string const & target)
{
	
	char challenges[5][30] = {"Blindfolded Food Eating ", "Baby Food Gobbling ", "Ice Bucket " , "Chubby Bunny ", "Brain Freezer "};
	srand(time(0));
	static int i;
	i += rand();
	std::cout<<"Sc4v-TP "<<Name<<" challenges "<<target<<" "<<challenges[abs(i)%4]<<"Chanllege"<<std::endl;
}