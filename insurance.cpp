#include "insurance.h"
//создаем нужный нам экземпляр класса
Insurance* InsuranceFactory::construct(Agreement* value) {
    switch (value->Type()) {
    case Agreement::InsuranceType::Car:
        return new InsCar;
    break;
    case Agreement::InsuranceType::Life:
        return new InsLife;
    break;
    case Agreement::InsuranceType::Home:
        return new InsHome;
    break;
    case Agreement::InsuranceType::Liability:
        return new InsLiability;
    break;
    default:
        return nullptr;
    break;
    }
}
