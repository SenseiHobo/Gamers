#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector> 
#include <cstdlib> 

#include "hero.h"
#include "menu.h"
#include "game.h"
#include "element.h"
#include "Tool.h"


std::string username = "sammy";
std::string password = "#Superdeadcasp2004";


void Database::createHero(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  
    db.setPassword(QString::fromStdString(password));  
    if (!db.open()) {
        qDebug() << "Database connection failed";
    }

    system("clear");

    int xp = 0 , level = 1, maxHP = 10, damage = 2, strength = 2, gold = 0, mana = 10;
    
    


    std::string name;

    Too.slow_print("You are creating a new Hero");
    std::cout << std::endl << std::endl; 

    Too.slow_print("Indtast din Helts navn: "); 
    std::cin >> name;
    std::cout << std::endl; 

    QSqlQuery query;
    query.prepare("INSERT INTO hero (name, level, xp, maxHP, damage, strength, gold, mana) VALUES (:name, :level, :xp, :maxHP, :damage, :strength, :gold, :mana)");


    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":level", level);
    query.bindValue(":xp", xp);
    query.bindValue(":maxHP", maxHP);
    query.bindValue(":damage", damage);
    query.bindValue(":strength", strength);
    query.bindValue(":gold", gold);
    query.bindValue(":mana", mana);

    if (!query.exec()) {
        qDebug() << "Failed to insert hero into database:" << query.lastError().text();
    } else {
        qDebug() << "Hero successfully created in database.";
    }

    db.close();
    M1.selector();
}


void Database::ShowHeroes(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username)); 
    db.setPassword(QString::fromStdString(password));  
    if (!db.open()) {
        qDebug() << "Database connection failed";
    }

    system("clear");

    Too.slow_print("You are looking at current Heroes");
    std::cout << std::endl << std::endl;

    QSqlQuery query;
    if (query.exec("SELECT * FROM hero")) {
        while (query.next()) {
            QString name = query.value(0).toString();
            int Level = query.value(1).toInt();
            int xp = query.value(2).toInt();
            int maxHP = query.value(3).toInt();
            int damage = query.value(4).toInt();
            int strength = query.value(5).toInt();
            int gold = query.value(6).toInt();
            int mana = query.value(7).toInt();

            qDebug() << "Hero name: " << name << "|  Level: " << Level << "|  xp " << xp << "|  maxHP: " << maxHP << "|  Mana: " << mana << "|  Damage: " << damage << "|  strength: " << strength << "|  Gold: " << gold;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    db.close();
    std::cout << std::endl << std::endl; 
    M1.selector();
}


const std::vector<std::shared_ptr<Spell>>& spells = DB1.createSpells();


void Database::loadHero(const std::vector<std::shared_ptr<Spell>>& spells) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));
    db.setPassword(QString::fromStdString(password));
    if (!db.open()) {
        qDebug() << "Database connection failed";
        return;
    }


    Too.slow_print("You are loading an existing hero");
    std::cout << std::endl;

    std::string name;
    Too.slow_print("Enter the name of the hero you want to play as: ");
    std::cin >> name;
    std::cout << std::endl;

    QString qName = QString::fromStdString(name);
    QSqlQuery query;
    query.prepare("SELECT level, xp, maxHP, damage, strength, gold, mana FROM hero WHERE name = :name");
    query.bindValue(":name", qName);


    if (query.exec()) {
        if (query.next()) {
            god = Hero(name, query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt(), query.value(4).toInt(), query.value(5).toInt(), query.value(6).toInt());

            // Create a map from spell ID to spell for quick lookup
            std::unordered_map<int, std::shared_ptr<Spell>> spellMap;
            for (const auto& spell : spells) {
                spellMap[spell->getID()] = spell;
            }

            // Load spells for hero
            query.prepare("SELECT spell_id FROM hero_spells WHERE hero_name = :name");
            query.bindValue(":name", qName);
            if (query.exec()) {
                while (query.next()) {
                    int spellId = query.value(0).toInt();
                    auto it = spellMap.find(spellId);
                    if (it != spellMap.end()) {
                        god.learnSpell(it->second);
                        std::cout << "Learned spell: " << it->second->getName() << std::endl;
                    }
                }
            }
        } else {
            qDebug() << "No hero found with the name: " << qName;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    db.close();
    system("clear");
    std::vector<Enemy> enemies = setupEnemies();
    G1.start_game(god, enemies);



}


void Database::deleteHero(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  
    db.setPassword(QString::fromStdString(password)); 
    if (!db.open()) {
        qDebug() << "Database connection failed";
    }



    std::string name;
    Too.slow_print("Enter the name of the hero to delete: ");
    std::cin >> name;
    std::cout << std::endl;

    QSqlQuery query;
    query.prepare("DELETE FROM hero WHERE name = :name");
    query.bindValue(":name", QString::fromStdString(name));

    system("clear");
    if (!query.exec()) {
        qDebug() << "Failed to delete hero from database:" << query.lastError().text();
    } else {
        qDebug() << "Hero successfully deleted from database.";
    }

    db.close();
    M1.selector();


}

void Database::saveCharacter(Hero &god){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username)); 
    db.setPassword(QString::fromStdString(password));  
    if (!db.open()) {
        qDebug() << "Database connection failed";
        return;
    }

    system("clear");

    // Update hero details
    QSqlQuery query(db);
    query.prepare("UPDATE hero SET level = :level, xp = :xp, maxHP = :maxHP, damage = :damage, strength = :strength, gold = :gold, mana = :mana WHERE name = :name");
    query.bindValue(":level", god.getlevel());
    query.bindValue(":xp", god.getXP());
    query.bindValue(":maxHP", god.getMaxHP());
    query.bindValue(":damage", god.getDamage());
    query.bindValue(":strength", god.getStrength());
    query.bindValue(":gold", god.getGold());
    query.bindValue(":mana", god.getMana());
    query.bindValue(":name", QString::fromStdString(god.getName()));

    if (!query.exec()) {
        qDebug() << "Error updating hero:" << query.lastError().text();
    } else {
        qDebug() << "Hero updated successfully: " << QString::fromStdString(god.getName());
    }

    // Insert new spells
    for (auto& spell : god.getSpells()) {
        query.prepare("INSERT INTO spells (name, damage, element, gold_price, hero_name) VALUES (:name, :damage, :element, :gold_price, :hero_name) ON DUPLICATE KEY UPDATE damage = :damage, element = :element, gold_price = :gold_price");
        query.bindValue(":name", QString::fromStdString(spell->getName()));
        query.bindValue(":damage", spell->getDamage());
        query.bindValue(":element", QString::fromStdString(elementToString(spell->getElement())));
        query.bindValue(":gold_price", spell->getGoldPrice());
        query.bindValue(":hero_name", QString::fromStdString(god.getName()));

        if (!query.exec()) {
            //qDebug() << "Error inserting spell:" << query.lastError().text();
        } else {
            qDebug() << "Spell inserted/updated successfully for hero: " << QString::fromStdString(god.getName());
        }
    }


    // Delete existing spells for the hero
    query.prepare("DELETE FROM hero_spells WHERE hero_name = :name");
    query.bindValue(":name", QString::fromStdString(god.getName()));
    if (!query.exec()) {
        qDebug() << "Failed to delete existing spells for hero:" << query.lastError().text();
        db.rollback(); // Rollback if delete fails
        return;
    }

    // Insert current spells for the hero
    for (const auto& spell : god.getSpells()) {
        query.prepare("INSERT INTO hero_spells (hero_name, spell_id) VALUES (:name, :spell_id)");
        query.bindValue(":name", QString::fromStdString(god.getName()));
        query.bindValue(":spell_id", spell->getID());
        if (!query.exec()) {
            qDebug() << "Failed to insert spell for hero:" << query.lastError().text();
            db.rollback(); // Rollback if any insert fails
            return;
        }
    }

    db.commit(); // Commit transaction
    qDebug() << "All spells for hero saved successfully.";
    db.close(); // Close the database connection
}



std::vector<std::shared_ptr<Spell>> Database::createSpells() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
     db.setUserName(QString::fromStdString(username));  
    db.setPassword(QString::fromStdString(password));  
    if (!db.open()) {
        qDebug() << "Database connection failed";
        return {};
    }

    QSqlQuery query("SELECT spell_id, name, damage, element, gold_price, required_spell_id, mana FROM spells_list");
    if (!query.exec()) {
        qDebug() << "Failed to query spells from database:" << query.lastError().text();
        return {};
    }

    std::vector<std::shared_ptr<Spell>> spellList;
    std::map<int, std::shared_ptr<Spell>> spellMap;

    while (query.next()) {
        int id = query.value(0).toInt();
        std::string name = query.value(1).toString().toStdString();
        int damage = query.value(2).toInt();
        Element element = stringToElement(query.value(3).toString().toStdString());
        int goldPrice = query.value(4).toInt();
        QVariant reqId = query.value(5);
        int mana = query.value(6).toInt();

        std::shared_ptr<Spell> requiredSpell = nullptr;
        if (!reqId.isNull()) {
            int reqSpellId = reqId.toInt();
            if (spellMap.find(reqSpellId) != spellMap.end()) {
                requiredSpell = spellMap[reqSpellId];
            }
        }

        std::shared_ptr<Spell> newSpell = std::make_shared<Spell>(id, name, damage, element, goldPrice, requiredSpell, mana);
        spellList.push_back(newSpell);
        spellMap[id] = newSpell;
    }

    db.close(); // Close the database connection
    return spellList;
}

Database DB1;