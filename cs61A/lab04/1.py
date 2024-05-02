from cats import report_progress
print_progress = lambda d: print('ID:', d['id'], 'Progress:', d['progress'])
typed = ['I', 'have', 'begun']
prompt = ['I', 'have', 'begun', 'to', 'type']
print_progress({'id': 1, 'progress': 0.6})