#include <stdio.h>

// 무기 데미지랑, 스킬 데미지를 넣어주면 그걸 합산해서 알려주는 함수
int calculateTotalDamage(int weaponDamage, int skillDamage) {
    int totalDamage = weaponDamage + skillDamage;
    printf("데미지 계산중... 크리티컬!!\n");
    return totalDamage;
}

int main(void) {
    
    int aaa = calculateTotalDamage(40, 68);
    printf("총 데미지: %d\n", aaa);


    return 0;
}