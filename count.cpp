int minLight = 150,
photoValue1 = 0,
photoValue2 = 0,
photoPin1 = 2,
photoPin2 = 3;
int pNum = 0;
int count(void) {
	photoValue1 = analogRead(photoPin1);
	photoValue2 = analogRead(photoPin2);//��������������й�ǿ�ɼ�
	//�����ã�Serial.println(photocellValue1);Serial.println(photocellValue2);

	while (photoValue1 > minLight && photoValue2 > minLight) {
		photoValue1 = analogRead(photoPin1);
		photoValue2 = analogRead(photoPin2);
	}//�������������ɼ��Ĺ�ǿֵ�����ٽ�ֵʱ��������������ɼ���ǿ

	if (photoValue1 < minLight) {
		while (photoValue2 > minLight) {
			photoValue2 = analogRead(photoPin2);
		}
		while (photoValue1 < minLight) {
			photoValue1 = analogRead(photoPin1);
		}
		while (photoValue2 < minLight) {
			photoValue2 = analogRead(photoPin2);
		}
		pNum++;
	}//ʵ�ֵ����߽����ң�������1
	if (photoValue2 < minLight) {
		while (photoValue1 > minLight) {
			photoValue1 = analogRead(photoPin1);
		}
		while (photoValue2 < minLight) {
			photoValue2 = analogRead(photoPin2);
		}
		while (photoValue1 < minLight) {
			photoValue1 = analogRead(photoPin1);
		}
		pNum--;
	}//ʵ�ֵ����߳����ң�������1

	Serial.println(pNum);//output the number of people
	Serial.println(photoValue1);//output the value of
	Serial.println(photoValue2);
	Serial.println("����-");
	delay(10);
}