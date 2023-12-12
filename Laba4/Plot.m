data = load('file1.txt');
x = data(:, 1);
y = data(:, 2);

% Выбор степени полинома
degree = 2;

% Полиномиальная аппроксимация
p = polyfit(x, y, degree);

% Генерация данных для построения графика
x_fit = linspace(min(x), max(x), 1000);
y_polyfit = polyval(p, x_fit);

% Построение графика
figure;
plot(x, y, 'o', x_fit, y_polyfit, '-');
legend('Исходные данные', 'Полиномиальная аппроксимация');
xlabel('X');
ylabel('Y');
title('Аппроксимация функции');
grid on;
