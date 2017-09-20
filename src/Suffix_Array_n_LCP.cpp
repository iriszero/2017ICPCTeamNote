// s : �Է� ���ڿ�
// group : ���̻��� ù ���� (�Է� ���ڿ��� �� ����)
// sagroup : gap�� ���� Counting Sort ���� group
// gap : Counting Sort��, group�� �� ���Ҹ� ���ϴ� ����
// lcp : ���� ���� ���λ� ����


const bool cmp(int i, int j) {
	if (group[i] != group[j]) return group[i] < group[j];
	return group[i + gap] < group[j + gap];
}

void getSuffixArray() {
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		group[i] = s[i];
	}

	group[n] = -1, sagroup[n] = -1, gap = 1;

	while (gap < n) {					// Counting Sort
		sort(sa, sa + n, cmp);
		for (int i = 1; i < n; i++)
			sagroup[i] = sagroup[i - 1] + cmp(sa[i - 1], sa[i]);
		for (int i = 0; i < n; i++) group[sa[i]] = sagroup[i];

		if (sagroup[n - 1] == n - 1) break;
		gap *= 2;
	}
}
}

void getLcpArray() {
	for (int i = 0, k = 0; i < n; i++) {
		if (group[i] == 0) lcp[group[i]] = 0;
		else {
			for (int j = sa[group[i] - 1]; s[i + k] == s[j + k]; k++);
			lcp[group[i]] = k;

			if (k != 0) k--;
		}
	}
}
