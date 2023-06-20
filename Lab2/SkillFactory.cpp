#include "SkillFactory.h"

Skill* SkillFactory::produce() {
    int select;
    FreeSkills();
    std::cin >> select;
    skills++;

    switch (select) {
    case 1: return new FireBall;
    case 2: return new Roots;
    case 3: return new PowerfulHit;
    case 4: return new IceShard;
    case 5: return new Hit;
    case 6: {
        if (type == "bountyhunter") return new Lasso;
        else if (type == "crossbowman") return new PowerfulShot;
        else if (type == "crusader")    return new ShiningShield;
        else if (type == "occultist")   return new Curse;
        else if (type == "sniper")  return new Shrapnel;
        else if (type == "summoner")    return new Summon;
    }
    }
}

void SkillFactory::FreeSkills()
{
    std::cout << name << ", choose your skills (" << skills << "/3):\n1.Fireball\t4.Ice Shards\n2.Roots\t\t5.Hit\n3.Powerful Hit\t";
    std::cout << "6." << SpecialSkills() << " (special)"<< std::endl;
}

std::string SkillFactory::SpecialSkills()
{
    if (type == "bountyhunter") return "Lasso";
    else if (type == "crossbowman") return "Powerful Shot";
    else if (type == "crusader")    return "Shining shield";
    else if (type == "occultist")   return "Curse";
    else if (type == "sniper")  return "Shrapnel";
    else if (type == "summoner")    return "Summon";
}
