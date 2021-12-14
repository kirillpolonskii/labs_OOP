#include "position.h"

Position::Position() {}

Position::Position(int latitude, int longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}

Position Position::operator +(const Position &b){
    int newLat = latitude + b.latitude;
    int newLong = longitude + b.longitude;
    if(newLat > 90 || newLat < -90){
        newLat = 180 - abs(newLat);
    }
    if(newLong < -180){
        newLong = 360 + newLong;
    }
    else if(newLong > 180){
        newLong = newLong - 360;
    }
    return Position(newLat, newLong);
}

Position Position::operator -(const Position &b){
    int newLat = latitude - b.latitude;
    int newLong = longitude - b.longitude;
    if(newLat > 90 || newLat < -90){
        newLat = 180 - abs(newLat);
    }
    if(newLong < -180){
        newLong = 360 + newLong;
    }
    else if(newLong > 180){
        newLong = newLong - 360;
    }
    return Position(newLat, newLong);
}

Position Position::operator *(const Position &b){
    int newLat = latitude * b.latitude;
    int newLong = longitude * b.longitude;
    if (newLat > 90){
        newLat %= 90;
    }
    else if (newLat < -90){
        newLat *= -1;
        newLat %= 90;
        newLat *= -1;
    }
    if (newLong > 180){
        newLong %= 180;
    }
    else if (newLong < -180){
        newLong *= -1;
        newLong %= 180;
        newLong *= -1;
    }
    return Position(newLat, newLong);
}

Position Position::operator /(const Position &b){
    int newLat = latitude / b.latitude;
    int newLong = longitude / b.longitude;
    return Position(newLat, newLong);
}

bool operator ==(Position a, Position b){
    return a.latitude == b.latitude && a.longitude == b.longitude;
}

void Position::Compare(Position a, Position b){
    if (a == b){
        std::cout << "Positions are equal\n";
    }
    else{
        if (a.latitude == b.latitude){
            std::cout << "Positions have the same latitude and ";
        }
        else if(a.latitude > b.latitude){
            std::cout << "First position is northern than second and ";
        }
        else{
            std::cout << "Second position is northern than first and ";
        }
        if (a.longitude == b.longitude){
            std::cout << "positions have the same longitude\n";
        }
        else if(a.longitude > b.longitude){
            std::cout << "first position is eastern than second\n";
        }
        else{
            std::cout << "second position is eastern than first\n";
        }
    }
}
std::istream& operator >>(std::istream& is, Position &pos){
    is >> pos.latitude >> pos.longitude;
    return is;
}
std::ostream& operator <<(std::ostream& os, Position &pos){
    os << "latitude, longitude: (" << pos.latitude << "," << pos.longitude << ")\n";
    return os;
}

Position operator "" _pos(const char* str, size_t size) {
    std::string strLat, strLong;
    int i = 0;
    while(str[i] != ','){
        strLat.push_back(str[i]);
        ++i;
    }
    ++i;
    while(str[i] != '\0'){
        strLong.push_back(str[i]);
        ++i;
    }
    int latitude = std::stoi(strLat), longitude = std::stoi(strLong);

    return Position(latitude, longitude);
}

