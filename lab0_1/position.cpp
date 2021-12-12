#include "position.h"

Position::Position(int latitude, int longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}

Position Position::Sum(Position a, Position b){
    int newLat = a.latitude + b.latitude;
    int newLong = a.longitude + b.longitude;
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

Position Position::Diff(Position a, Position b){
    int newLat = a.latitude - b.latitude;
    int newLong = a.longitude - b.longitude;
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

Position Position::Mult(Position a, Position b){
    int newLat = a.latitude * b.latitude;
    int newLong = a.longitude * b.longitude;
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

Position Position::Substr(Position a, Position b){
    int newLat = a.latitude / b.latitude;
    int newLong = a.longitude / b.longitude;
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

void Position::print(){
    std::cout << "latitude, longitude: (" << latitude << "," << longitude << ")\n";
}


