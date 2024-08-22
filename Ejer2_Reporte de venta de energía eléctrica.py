import pandas as pd

def productos_vencidos(productos, anho, mes, dia):
    fecha_referencia = pd.Timestamp(year=anho, month=mes, day=dia)
    productos['fecha_vencimiento'] = pd.to_datetime(productos[['anho', 'mes', 'dia']].rename(columns={'anho': 'year', 'mes': 'month', 'dia': 'day'}))
    vencidos = productos[productos['fecha_vencimiento'] < fecha_referencia]
    return vencidos[['anho', 'mes', 'dia']]

productos = pd.DataFrame({
    'anho': [2025, 2024, 2023, 2024],
    'mes': [5, 2, 10, 6],
    'dia': [28, 14, 24, 1]
}, index=['chocosoda', 'doritos', 'ritz', 'lays'])

resultados = productos_vencidos(productos, 2024, 3, 21)
print(resultados)