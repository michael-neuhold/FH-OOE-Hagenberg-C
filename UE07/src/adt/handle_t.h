//
// Created by Michael Neuhold on 01.12.19.
//

#ifndef ADT_HANDLE_T_H
#define ADT_HANDLE_T_H


class handle_t {

public:
    handle_t(int index);
    ~handle_t() = default;
    int getIdentifier() const;

private:
    int identifier;

};

#endif //ADT_HANDLE_T_H
