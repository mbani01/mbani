/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:45:20 by mbani             #+#    #+#             */
/*   Updated: 2021/02/15 10:53:24 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy
{
protected:
    int hp;
    std::string type;
    Enemy();
// private:
public:
    Enemy(int hp, std::string const & type);
    Enemy(const Enemy &);
    void operator=(const Enemy &);
    int getHP() const;
    std::string getType() const;
    virtual void takeDamage(int);
    virtual ~Enemy();
};

#endif