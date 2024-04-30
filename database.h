#ifndef DATABASE_H
#define DATABASE_H


#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <memory>
#include "spell.h"
#include "hero.h"

void createHero();
void ShowHeroes();
void loadHero(const std::vector<std::shared_ptr<Spell>>& spells);
void deleteHero();
void saveCharacter(Hero &god);
std::vector<std::shared_ptr<Spell>> createSpells();
#endif //DATABASE_H