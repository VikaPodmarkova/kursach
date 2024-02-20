/** @file
* @author Подмарькова В.О.
* @version 1.0
* @date 20.02.2024
* @copyright ИБСТ ПГУ
* @warning Курсовая работа студента
* @brief Заголовочный файл для модуля mdfile
*/
#pragma once
#include <netinet/in.h>
#include <map>
#include <limits>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <boost/program_options.hpp>
#include <memory>
#include <random>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
using namespace CryptoPP;
#include <cryptopp/md5.h>
#include<exception>
#include<ctime>
class ServerError: public std::runtime_error{
    public:
    /** @brief Класс ServerError
* @details 
*/
    ServerError(const char* msg): std::runtime_error(msg){};
    ServerError(const std::string &msg): std::runtime_error(msg){};
};
/** @brief Класс LogWriter
* @details Для записи ошибок предназначен метод log
*/
class LogWriter
{
public:
 /**
    * @brief Запись ошибок
    * @param [in] way путь к файлу для записи 
    * @param [in] msg текст ошибки
    * @return Метод ничего не возвращает
    */
    static void log(std::string &way, std::string msg );
};
