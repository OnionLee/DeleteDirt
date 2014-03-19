DeleteDirt
==========
<<<<<<< HEAD
=======
[create(imagefilename,maskfilename)]
로 초기화를 합니다.
>>>>>>> origin/patch-1

###create(imagefilename,maskfilename)
+원본이미지 파일 경로, 마스크 이미지 파일 경로로 초기화 합니다.

###SetDrawWithPos(CCPoint pos)
+원하는 위치에 마스킹 이미지를 그립니다.

###SetMaskingWithPos(CCPoint pos)
+원하는 위치에 마스킹을 적용 시킵니다.

+Draw같은 경우는 그림그리듯이 할 수 있고,
Masking은 적용시 화면의 이미지가 초기화 됩니다.

###SetMaskingSize(float size);
+마스킹 사이즈를 지정 할 수 있습니다.

###SetImageClear();
+화면의 이미지를 초기화 합니다.
