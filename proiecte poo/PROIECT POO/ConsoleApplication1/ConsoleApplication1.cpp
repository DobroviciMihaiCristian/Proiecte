#include <iostream>
#include <cstring>
#include <vector>


class Car
{
private:
    char* marca;
    char* model;
    char* an;

public:
    Car()
    {
        this->marca = new char[1];
        this->model = new char[1];
        this->an = new char[1];
        this->marca[0] = 0;
        this->model[0] = 0;
        this->an[0] = 0;
    }
    Car(const char* _marca, const char* _model, const char* _an)
    {
        this->marca = new char[strlen(_marca) + 1];
        this->model = new char[strlen(_model) + 1];
        this->an = new char[strlen(_an) + 1];
        strcpy(this->marca, _marca);
        strcpy(this->model, _model);
        strcpy(this->an, _an);
    }
    Car(const Car& other)
    {
        this->marca = new char[strlen(other.marca) + 1];
        this->model = new char[strlen(other.model) + 1];
        this->an = new char[strlen(other.an) + 1];
        strcpy(this->marca, other.marca);
        strcpy(this->model, other.model);
        strcpy(this->an, other.an);
    }
    Car& operator=(const Car& other)  
    {
        char* new_marca = new char[strlen(other.marca) + 1];
        char* new_model = new char[strlen(other.model) + 1];
        char* new_an = new char[strlen(other.an) + 1];
        strcpy(new_marca, other.marca);
        strcpy(new_model, other.model);
        strcpy(new_an, other.an);
        delete[] this->marca;
        delete[] this->model;
        delete[] this->an;
        this->marca = new_marca;
        this->model = new_model;
        this->an = new_an;
        return *this;
    }
    char* get_marca()
    {
        return this->marca;
    }
    char* get_model()
    {
        return this->model;
    }
    char* get_an()
    {
        return this->an;
    }
    ~Car()
    {
        delete[] this->marca;
        delete[] this->model;
        delete[] this->an;
    }
};

using namespace std;

int main()
{
    cout << "Bun venit !\n";
    int n;
    cout << "Introduceti numarul de masini: ";
    cin >> n;
    if (n == 0)    cout << "Nu ati introdus nicio masina";
    else {
        vector<Car> cars;
        for (int i = 0; i < n; i++)
        {
            string marca;
            cout << "Introduceti marca masinii: ";
            cin >> marca;
            string model;
            cout << "Introduceti modelul masinii: ";
            cin >> model;
            string an;
            cout << "Introduceti anul masinii: ";
            cin >> an;
            Car cur_car(marca.c_str(), model.c_str(), an.c_str());
            cars.push_back(cur_car);
        }
        cars.push_back(Car());
        cars[n] = cars[n - 1];

        cout << "Masinile introduse sunt :\n";
        for (int i = 0; i <= n; i++)
        {
            cout << "Marca masinii: " << cars[i].get_marca() << ", Modelul masinii: " << cars[i].get_model() << ", Anul masinii: " << cars[i].get_an() << "\n";
        }
    }
}
