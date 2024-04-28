#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

#include <iostream>
#include <string>

#include "hero.h"
#include "menu.h"
#include "game.h"

std::string username = "sammy";
std::string password = "#Superdeadcasp2004";


void createHero(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  // Husk at ændre til dit brugernavn
    db.setPassword(QString::fromStdString(password));  // Husk at ændre til din adgangskode
    if (!db.open()) {
        qDebug() << "Database connection failed";
    }

    int xp = 0 , level = 1, maxHP = 10, damage = 2, strength = 2; 
    std::string name;

    std::cout << "Indtast din Helt navn: "; 
    std::cin >> name;
    std::cout << std::endl; 

    QSqlQuery query;
    query.prepare("INSERT INTO hero (name, level, xp, maxHP, damage, strength) VALUES (:name, :level, :xp, :maxHP, :damage, :strength)");

// Bind values to the named placeholders
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":level", level);
    query.bindValue(":xp", xp);
    query.bindValue(":maxHP", maxHP);
    query.bindValue(":damage", damage);
    query.bindValue(":strength", strength);

    if (!query.exec()) {
        qDebug() << "Failed to insert hero into database:" << query.lastError().text();
    } else {
        qDebug() << "Hero successfully created in database.";
    }

    selector();
}


void ShowHeroes(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  // Husk at ændre til dit brugernavn
    db.setPassword(QString::fromStdString(password));  // Husk at ændre til din adgangskode
    if (!db.open()) {
        qDebug() << "Database connection failed";
    }

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

            qDebug() << "Hero name: " << name << " Level: " << Level << "xp " << xp << "maxHP: " << maxHP << "Damage: " << damage << "strength: " << strength << "Gold: " << gold;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    std::cout << std::endl << std::endl; 
    selector();
}



void loadHero() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  // Husk at ændre til dit brugernavn
    db.setPassword(QString::fromStdString(password));  // Husk at ændre til din adgangskode
    if (!db.open()) {
        qDebug() << "Database connection failed";
        return;  // Exit the function if connection fails
    }

    std::string name; 
    std::cout << "Enter the name of the hero you want to play as: ";
    std::cin >> name; 
    std::cout << std::endl;

    QSqlQuery query;
    query.prepare("SELECT level, xp, maxHP, damage, strength FROM hero WHERE name = :name");
    query.bindValue(":name", QString::fromStdString(name));

    int level;
    int xp;
    int maxHP;
    int damage;
    int strength;
    int gold;


    if (query.exec()) {
        if (query.next()) {
            level = query.value(0).toInt();
            xp = query.value(1).toInt();
            maxHP = query.value(2).toInt();
            damage = query.value(3).toInt();
            strength = query.value(4).toInt();
            gold = query.value(5).toInt();
            god = Hero(name, level, xp, maxHP, strength, gold);

            qDebug() << "Loaded Hero: " << QString::fromStdString(name) << " - Level:" << level << " XP:" << xp
                     << " MaxHP:" << maxHP << " Damage:" << damage << " Strength:" << strength;
        } else {
            qDebug() << "No hero found with the name: " << QString::fromStdString(name);
            selector(); 
            
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    std::vector<Enemy> enemies = setupEnemies();
    start_game(god, enemies);

}   




void deleteHero(){


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  // Husk at ændre til dit brugernavn
    db.setPassword(QString::fromStdString(password));  // Husk at ændre til din adgangskode
    if (!db.open()) {
        qDebug() << "Database connection failed";
    }

    std::string name;
    std::cout << "Enter the name of the hero to delete: ";
    std::cin >> name;
    std::cout << std::endl;

    QSqlQuery query;
    query.prepare("DELETE FROM hero WHERE name = :name");
    query.bindValue(":name", QString::fromStdString(name));

    if (!query.exec()) {
        qDebug() << "Failed to delete hero from database:" << query.lastError().text();
    } else {
        qDebug() << "Hero successfully deleted from database.";
    }

    selector();


}


void saveCharacter(Hero &god){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hobo_adventure");
    db.setUserName(QString::fromStdString(username));  // Husk at ændre til dit brugernavn
    db.setPassword(QString::fromStdString(password));  // Husk at ændre til din adgangskode
    if (!db.open()) {
        qDebug() << "Database connection failed";
        return;  // Exit the function if connection fails
    }


    QSqlQuery query;
    query.prepare("UPDATE hero SET level = :level, xp = :xp, maxHP = :maxHP, damage = :damage, strength = :strength, gold = :gold WHERE name = :name");
    query.bindValue(":level", god.getlevel());
    query.bindValue(":xp", god.getXP());
    query.bindValue(":maxHP", god.getMaxHP());
    query.bindValue(":damage", god.getDamage());
    query.bindValue(":strength", god.getStrength());
    query.bindValue(":gold", god.getGold());
    query.bindValue(":name", QString::fromStdString(god.getName()));

    // Execute the query
    if (query.exec()) {
        qDebug() << "Hero updated successfully: " << QString::fromStdString(god.getName());
    } else {
        qDebug() << "Error updating hero:" << query.lastError().text();
    }
}
