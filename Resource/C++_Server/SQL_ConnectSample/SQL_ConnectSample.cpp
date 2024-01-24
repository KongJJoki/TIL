#include <iostream>

#include "mysql/include/mysql/jdbc.h" // include 폴더 경로로 들어가서 jdbc.h 헤더 추가
#pragma comment(lib, "mysql/lib64/vs14/debug/mysqlcppconn.lib") // lib64 폴더 경로로 들어가서 라이브러리 추가

int main()
{
    // sql 드라이버 얻기

    auto driver = sql::mysql::get_driver_instance(); // 드라이버 얻어오는 함수?

    // 커넥트 시도 -> 성공시 커넥트 객체 얻기

    auto con = driver->connect("tcp://3.38.115.189:3306", "test", "1234"); // 주소는 선생님 aws 설치된 공용 ip주소 뒤에는 아이디 비밀번호

    // 코드에서는 DB를 만들거나, 수정하거나 하는건 안한다고 보면 됨 / 그런건 DB 툴로 한다
    // DB 선택

    con->setSchema("sample"); // 어떤 DB 쓸건지(스키마) 매개변수가 DB 이름

    // 처리기

    auto stmt = con->createStatement();
    // 트랜잭션(commit, rollback)같은거 con에서 걸 수 있음

    // 쿼리 날리거나 처리하기

    auto res = stmt->executeQuery("select * from tb_pvlog"); // 결과 안받아도 되면 execute 결과 받아야하면 executeQuery
    auto metaData = res->getMetaData(); // 메타데이터 얻어오기
    auto columeCnt = metaData->getColumnCount(); // 메타데이터에서 column개수 얻어오기

    while (res->next())// res->next로 한개씩 빼다가 다 나오면 null나오면 while 탈출
    {
        for (int i = 0; i < columeCnt; i++) // 얻어온 column 개수만큼 반복문 돌리기
        {
            std::cout << res->getString(i + 1) << "\t\t"; // SQL은 인덱스 1부터 시작이라서 i + 1 해주기
        }
        std::cout << '\n';
    }

    // 처리기랑 커넥트 해제
    delete stmt;
    delete con;
    delete res;
    
    // 다 썼으면 해제
    // delete driver; // 내부에서 지워주는 처리 있는듯 직접 지우면 에러남

    system("pause");
}