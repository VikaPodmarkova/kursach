#include "Calculator.h"
void Calculator::math(int work_sock, std::string &err_way)
{
    uint32_t amount;
    uint32_t vector_size;
    
    recv(work_sock, &amount, sizeof amount, 0);

    for(uint32_t i=0; i<amount; i++) {
        recv(work_sock, &vector_size, sizeof vector_size, 0);
        std::unique_ptr<int64_t[]> v(new int64_t[vector_size]);

        int v_size;
        uint32_t ex_size = sizeof(int64_t)*vector_size;
        if ((v_size = recv(work_sock, (void*)v.get(), ex_size, 0)) == -1) {
            throw ServerError("Ошибка получения вектора");
        }
        if (ex_size != (uint32_t)v_size) {
            throw ServerError("Размер вектора не совпал с ожидаемым");
        }

        int64_t sum = 0;
        for(uint32_t j=0; j<vector_size; j++) {
            if (v[j] == 0) {
                continue;
            }
            int64_t squared_number = v[j] * v[j];
            if (v[j] != (squared_number / v[j])) {
                sum = std::numeric_limits<int64_t>::max();
                break;
            }
            if (sum > std::numeric_limits<int64_t>::max() - squared_number) {
                sum = std::numeric_limits<int64_t>::max();
                break;
            }
            sum = sum + squared_number;
        }
        send(work_sock, &sum, sizeof sum, 0);
    }

    LogWriter::log(err_way, "Результат вычислений получен и отправлен клиенту");
    std::cout << "Program finish!" <<std::endl;
    close(work_sock);
}
