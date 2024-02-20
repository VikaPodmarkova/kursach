/** @file
* @author Подмарькова В.О.
* @version 1.0
* @date 20.02.2024
* @copyright ИБСТ ПГУ
* @warning Курсовая работа студента
* @brief Заголовочный файл для модуля User_Interface
*/

#define UNIT_TEST
#include "mdfile.h"
#include "Calculator.h"
#pragma once
namespace po = boost::program_options;
/** @brief Класс User_Interface
* @details Для взаимодействия сервера с командной строкой предназначены 
* методы: operator для запуска сервера 
* и User_Interface для обработки параметров командной строки
* и UI_err для обработки ошибок парсера
* @warning Все параметры для ввода являются обязательными
*/
class User_Interface
{
////for test
#ifdef UNIT_TEST
public:
    std::string file;
    std::string LogWrite;
    int port;
     /**
	* @brief Метод UI_err для обработки ошибок
	* @param Без параметров
	* @return Метод ничего не возвращает
    * @throw ServerError, если отсутствует обязательный параметр
	*/
#else
private:
 ///описание параметров командной строки 
    po::options_description descr;
    /// значения параметров командной строки
    po::variables_map vm;
    ///путь к файлу с базой данных
    std::string file;
    ///путь к журналом работы   
    std::string LogWrite;
    ///номер порта   
#endif
    po::options_description descr;
    po::variables_map vm;
    //std::string file;
    //std::string LogWrite;
    //int port;
    void Input();

public:
    bool flag = true;
    User_Interface() = delete;
     /**
    * @brief Метод User_Interface обработки параметров командной строки
	* @param Параметры командной строки
	* @return Метод ничего не возвращает
	*/
    User_Interface(int argc, char **argv);
      /**
	* @brief Метод operator для запуска сервера
	* @param Без параметров
	* @return Метод ничего не возвращает
	*/
    void operator()();
};
