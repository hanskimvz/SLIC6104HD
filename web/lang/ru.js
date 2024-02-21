export default {
  route: {
    dashboard: 'Живое видео',
    network_settings: 'Сетевые настройки',
    ip_settings: 'Настройка IP',
    gb28181_settings: 'GB28181 Settings',
    media_settings: 'Настройки медиа',
    video_capture: 'Запись',
    datetime_title: 'Время и текст',
    video_codec: 'Видео кодек',
    audio_capture: 'Видео кодек',
    audio_codec: 'Аудио кодек',
    fill_light: 'Свет для заправки',
    privacy_mask: 'Маска для защиты данных',
    warning_settings: 'Настройки тревоги ',
    human_recognition: 'Обнаружение человека   ',
    motion_detection: 'Детектор движения',
    occlusion_detection: 'Обнаружение масок',
    system_settings: 'Системные настройки',
    user_management: 'Пользовательские настройки',
    system_time: 'Системное время',
    maintenance: 'Обслуживание системы',
    documentation: 'Документация',
    guide: 'Год',
    permission: 'Аутентификация',
    pagePermission: 'Страница аутентификации',
    rolePermission: 'Роль',
    directivePermission: 'Удостоверение подлинности в соответствии с директивой',
    page401: '401',
    page404: '404',
    errorLog: 'Журнал ошибок',
    theme: 'По теме:',
    clipboardDemo: 'Глобализация и развитие',
    i18n: 'I18n',
    externalLink: 'Профиль',
    profile: 'Профиль',
    language: 'Язык',
    storage: 'Настройки хранилища',
    ptzcontrol: 'PTZ контроль',
    audio_settings: 'Настройки аудио',
    network_protocol: 'Сетевой протокол',
    platform_settings: 'Настройки платформы',
    ai_settings: 'Параметры ии',
    video_coding: 'Кодирование',
    image_parameters: 'Параметры изображения',
    capture_settings: 'Настройки записи',
    osd_settings: 'Настройки OSD',
    devices_maintenance: 'Обслуживание устройств'
  },
  dashboard: {
    name: 'Имя',
    id: 'ID',
    version: 'Версия',
    monitor: 'Монитор',
    intercom: 'Интерком',
    snapshot: 'Снимок',
    videotape: 'Видео'
  },
  navbar: {
    dashboard: 'Живое видео',
    github: 'Github',
    logOut: 'Выйти',
    profile: 'Профиль',
    theme: 'Тема',
    size: 'Размер'
  },
  login: {
    title: 'Форма входа в систему',
    logIn: 'Вход в систему',
    username: 'Пользователь',
    password: 'Пароль',
    any: 'any',
    thirdparty: 'Логин третьей стороны',
    thirdpartyTips: 'Не могут быть смоделированы на местном, пожалуйста, объединить с вашим собственным бизнесом для моделирования! ! !'
  },
  permission: {
    addRole: 'Новая роль',
    editPermission: 'Редактировать',
    roles: 'Ваши роли',
    switchRoles: 'Смена ролей',
    tips: '',
    delete: 'Удалить',
    confirm: 'Подтвердить',
    cancel: 'Отмена'
  },
  errorLog: {
    tips: '',
    description: '',
    documentation: 'Введение к документу'
  },
  theme: {
    change: 'Тема < < изменение > >',
    documentation: 'Документация по теме',
    tips: ''
  },
  tagsView: {
    refresh: 'Обновить',
    close: 'Закрыть',
    closeOthers: 'Закрыть другие',
    closeAll: 'Закрыть все'
  },
  settings: {
    title: 'Настройка стиля страницы',
    theme: 'Цвет темы',
    tagsView: 'Открытые тэги-view',
    fixedHeader: 'Фиксированный заголовок',
    sidebarLogo: 'Логотип боковой панели'
  },
  button: {
    save: 'Сохранить',
    view: 'Вид',
    edit: 'Редактировать',
    all: 'Все',
    all_list: 'Весь лист',
    empty: 'Очистить',
    delete: 'Удалить',
    refresh: 'Обновить',
    search: 'Поиск',
    restart: 'Перезапуск',
    setting: 'Параметры',
    updatesoft: 'Обновить софт',
    default: 'По умолчанию',
    restore_factory: 'Заодское значение',
    reset: 'Перезагрузить'
  },
  ip_settings: {
    mac_address: 'MAC Address',
    dhcp: 'DHCP',
    self_adaption: 'IP Self-Adaption',
    ipv4_addr: 'IPv4 адрес',
    ipv4_mask: 'IPv4 маска подсети',
    ipv4_gateway: 'IPv4 шлюз',
    ipv6_addr: 'IPv6 адрес',
    ipv6_gateway: 'IPv6 шлюз',
    dns1: 'DNS1',
    dns2: 'DNS2',
    ip_settings: 'Настройка IP',
    auto_ip: 'Автоматический IP',
    static_ip: 'Статический IP',
    static_ddns: 'Статический DDNS',
    auto_ddns: 'Автоматический DDNS'
  },
  gb28181_settings: {
    enabled: 'Использовать 28181',
    local_sip_port: 'Локальный SIP порт(1025-65525',
    sip_server_id: 'SIP сервер ID',
    sip_server_domain: 'Домен SIP сервера',
    sip_server_ip: 'IP адрес SIP сервера',
    sip_server_port: 'Порт SIP сервера(1-65535)',
    sip_username: 'Имя SIP пользователя',
    sip_user_auth_id: 'IP SIP пользователя',
    password: 'Пароль',
    password_confirm: 'Подтвердите пароль',
    term_of_validity: 'Срок действия (секунд)',
    heartbeat_cycle: 'Частота обновления(5-3600)',
    max_heartbeat_timeout: 'Максимальное время обновления(3-255)',
    stream_index: '28181 индекс потока',
    video_channel_code_id: 'ID кода видеоканала',
    audio_channel_code_id: 'ID кода аудиоканала',
    alarm_id: 'ID тревоги'
  },
  video_capture: {
    brightness: 'Яркость',
    contrast: 'Констраст',
    saturation: 'Насыщенность',
    backlight: 'Подсветка',
    sharpness: 'Стандарт видеоs',
    video_standard: 'Стандарт видео',
    horizontal_flip: 'Отразить по горизонтали',
    vertical_flip: 'Отразить по вертикали',
    prevent_overexposure: 'Местоположение',
    scene_mode: 'Местоположение',
    AE_sensitivity: 'AE допуск',
    AE_tolerance: 'AE допуск',
    exposure_mode: 'Режим экспозиции',
    white_balance: 'Баланс белого',
    wide_dynamic: 'WD',
    wide_dynamic_enhancement: 'WD коррекция',
    noise_reduction_3d: '3D шумоподавление',
    noise_reduction_3d_enhancement: 'Интенсивность 3D-шумоподавления',
    // 字符
    capture_setting: 'Предварительная настройка',
    advance_setting: 'Предварительная настройка',
    auto: 'Авто',
    indoor: 'В помещении',
    outdoor: 'Отключить',
    disable: 'Отключить',
    manual: 'Настроить'
  },
  datetime_title: {
    datetime: 'Дата и время',
    x: 'Доля в процентах (%)',
    y: 'Доля в процентах (%)',
    time_format: 'Формат времени',
    week: 'Шоу-неделя',
    date_format: 'Формат для даты',
    style: 'Стиль недели',
    title: 'Название сайта',
    channel: 'По каналу связи',
    enabled: 'Включена ли функция',
    name: 'Название канала',
    hour24: '24 часа',
    hour12: '12 часов',
    english: 'Английский язык',
    chinese: 'китайск'
  },
  video_codec: {
    main_stream: 'Основной поток',
    encode_format: 'Кодек',
    resolve: 'Разрешение',
    bitrate: 'Тип битрейта',
    framerate: 'частота кадров',
    bps: 'Битрейт',
    keyframe_interval: 'Интервал опорного кадра',
    sub_stream: 'Суб поток',
    // 字符
    h264: 'H.264',
    h265: 'H.265',
    quality: 'качеств',
    quality_tip: '（1-9 Чем выше числовое значение, тем лучше качество）',
    //  new add---------
    first_main_stream: 'Первый основной поток',
    first_sub_stream: 'Первый суб поток',
    second_main_stream: 'Второй основной поток',
    second_sub_stream: 'Второй суб поток',
    stream_id: 'Stream ID',
    profile: 'Профиль '
  },
  audio_capture: {
    sample_rate: 'Частота дискретизации',
    sample_bit: 'Глубина бит',
    collect_volume: 'Чувствительность',
    play_volume: 'Громкость воспроизведения',
    input_method: 'Вход'
  },
  audio_codec: {
    encode_enabled: 'Использовать',
    encode_format: 'Кодек',
    decode_enabled: 'Декодировать'
  },
  fill_light: {
    ir_cut: 'активация',
    light_mode: 'Световой режим',
    image_mode: 'Режим изображения',
    photosensitive_type: 'Светочувствительный тип',
    start_sensitivity: 'Источник света активирует чувствительность',
    automatic_sensitivity: 'Источник лампы автоматически регулирует чувствительность',
    light_type: 'Тип света',
    dimming_mode: 'Режим настройки света',
    luminance: 'Яркость света(100%)',
    // 字符
    forward: 'Направля к',
    reverse: 'обратн',
    infrared: 'Инфракрасный интеллект, настроенный на свет',
    white_warm_light: 'Умные настройки белого света/теплового света',
    dual_light_source: 'Двойной источник света (инфракрасный, белый свет/тепловой свет) — интеллектуальная фотомодуляция',
    auto: 'автоматическ',
    day: 'днем',
    night: 'ноч',
    timing: 'Замедлен действ',
    hard: 'Жесткая светочувствительность',
    soft: 'Мягкая светочувствительность',
    morning: 'утр',
    middle: 'В полден',
    evening: 'ноч',
    fast: 'быстр',
    slow: 'медлен',
    red_light: 'красн',
    warm_light: 'Тепл свет',
    manual: 'вручн'
  },
  privacy_mask: {
    privacy_zone: 'Частная зона',
    enabled: 'открыт',
    x: 'X координат',
    y: 'Y координат',
    width: 'ширин',
    height: 'высот',
    color: 'цвет'
  },
  user_management: {
    name: 'Имя пользователя.',
    password: 'код',
    group: 'Группа пользователей.',
    enabled: 'открыт',
    operations: 'операцион',
    edit: 'модификац',
    remove: 'удал',
    add: 'добавля',
    admin: 'Администратор.',
    operator: 'оператор',
    viewer: 'Наблюдатель',
    cancel: 'отмен',
    confirm: 'подтверд',
    input_user: 'Ввод информации пользователя',
    confirm_password: 'Введите еще раз',
    user: 'пользовател'
  },
  system_time: {
    mode: 'Способ работы',
    ntp_server: 'NTP сервер',
    port: 'NTP порт',
    sync_time: 'Частота синхронизации',
    timezone: 'Часовой пояс',
    time: 'Время',
    same_host: 'Согласуется с компьютером',
    ntp: 'NTP',
    manual: 'Заданное значенеи'
  },
  maintenance: {
    enabled: 'Разрешить',
    day: 'День технического обслуживания',
    restart_time: 'Время перезапуска',
    sunday: 'Воскресенье',
    monday: 'Понедельник',
    tuesday: 'Вторник',
    wednesday: 'Среда',
    thursday: 'Четверг',
    friday: 'Пятница',
    saturday: 'Суббота',
    everyday: 'Каждый день',
    am: 'a.m.',
    pm: 'p.m.',
    y: 'Год',
    m: 'Месяц',
    d: 'День'
  },
  human_recognition: {
    enabled: 'открыт',
    sensitivity: 'чувствительность',
    alarm_mode: 'Сигнализация.',
    flash_light: 'Сигнальные огни мигают',
    play_tone: 'Включай',
    area: 'региональн',
    defence: 'Время на оборону.',
    withdrawal: 'Время вывода.',
    days: 'День на часах',
    repeat: 'повторение',
    voice: 'Сигнализация.',
    m_f: 'С понедельника по пятницу',
    m_s: 'С понедельника по субботу.',
    sat_sun: 'Суббота и воскресенье',
    sun: 'В воскресен',
    everyday: 'Кажд ден',
    default: 'По умолчан'
  },
  occlusion_detection: {
    enabled: 'открыт',
    area: 'региональн',
    sensitivity: 'чувствительность',
    alarm_mode: 'Сигнализация.',
    flash_light: 'Сигнальные огни мигают',
    play_tone: 'Включай',
    tips: 'Нажмите на левую кнопку, передвиньте область, за которой нужно следить, и поддержите до четырех'
  },
  motion_detection: {
    enabled: 'открыт',
    sensitivity: 'чувствительность',
    alarm_mode: 'Сигнализация.',
    flash_light: 'Flash Light',
    play_tone: 'Сигнальные огни мигают'
  },
  ptzcontrol: {
    name: 'PTZ',
    amplify: 'Увеличь',
    focus: 'сфокусирова',
    aperture: 'диафрагм',
    ptz_speed: 'Скорость облаков',
    doubling_speed: 'Скорость изменения',
    focus_mode: 'Режим фокусировки',
    focus_sensitivity: 'Чувствительность к фокусировке',
    focus_area: 'Область фокусировки',
    preset_position: 'Занять позиции.',
    code_stream: 'Ярд поток',
    base_set: 'Основная установка',
    more_set: 'Больше настроек'
  },
  storage: {
    storage: 'Хранилище',
    media_format: 'Формат файла',
    image_save_path: 'Сохранять изображение в',
    video_save_path: 'Сохранять видео в',
    storage_device: 'TF карта',
    save_setting: 'Сохранить настройки',
    storage_Plan: 'Расписание',
    storage_management: 'Управление хранилищем',
    video_files: 'Видео файл',
    record_audio: 'Запись аудио',
    tf_card: 'TF карта',
    volume: 'Занято',
    status: 'статус',
    format: 'Форматировать',
    unformat: 'Не форматирована',
    usb_disk: 'USB диск',
    total: 'Полный',
    used: 'Используется',
    recording_status: 'Статус записи',
    working_mode: 'Рабочий режим',
    video_stream: 'Видеопоток',
    video_file_size: 'Размер файла',
    video_strategy: 'При заполнении хранилища',
    auto_override: 'Перезапись',
    full_stop: 'Остановить при заполнении',
    choose_time: 'Выбор времени',
    manual_recording: 'Ручная регистрация данных',
    timer_recording: 'Запись с таймером',
    recording_type: 'Вид видео',
    media_forma: 'Формат медиа',
    file_type: 'Тип файла',
    video_audio: 'Видео и аудио',
    onliy_video: 'Только видео',
    ftp: 'Загрузка FTP сервера',
    email: 'Отправляю e-mail',
    file_name: 'Имя файла',
    action: 'операцион',
    max_record_time: 'Максимальная длительность записи'
  },
  lg: {
    msg: 'Перевести язык успеха'
  },
  tf_card: {
    ok: "TF card Ok",
    no_card: "No TF card",
    no_format: "TF card not format",
    abnormal: "TF card abnormal",
    file_type: "Format type",
    is_delete: "Форматирована ли TF карта?",
    formatting: "Formatting TF Card!",
    cancel: "Все в силе",
    confirm: "увер",
  },
  network_settings: {
    name: 'Настройка сети',
    wired_network: 'Настройка wi-fi',
    wifi_settings: 'Настройка wi-fi',
    s4g_settings: 'Установка на 4G',
    ip_address_filtering: 'Фильтрация IP-адреса'

  },
  network_protocol: {
    enabled: 'открыт',
    name: 'Сетевой протокол',
    http: 'HTTP',
    rtsp: 'RTSP',
    rtp: 'RTP',
    ftp: 'FTP',
    smtp: 'SMTP',
    qos: 'Qos',
    x8021: '802.1x',
    upnp: 'uPnP',
    pppoe: 'PPPoE',
    ntf: 'NTP',
    ddns: 'DDNS',
    http_port: 'Порт Http',
    listening_port: 'Порт подслушивания',
    upgrade_port: 'Обновленный порт',
    multicast_ttl: 'Мультикаст TTL',
    identity_authentication: 'Удостоверение личности',
    rtmp:'RTMP',
    user:'Имя пользователя',
    password:'Пароль для входа',
    server_id:'服务器编号',
    server_url:'Адрес сервера',
    server_path:'Каталог серверов',
    path:'Путь к успеху',
    rtmp_enabled:'Включение RTMP',
    rstp_enabled:'Удостоверение личности',
    rtp_enabled:'Включение RTP',
    stream:'Поток видео',
    port:'Номер порта',
    video_id:'Видео-ID',
    audio_id:'Аудиоid',
    talk_id:'Идентификатор интеркома',
    mtu:'Mtu',
    udp:"UDP",
    udp_enabled:'Включите UDP Multicast',
    udp_ip:'Multicast IP-адрес',
    udp_port:'Номер порта',
    udp_url:'Адрес воспроизводится группой UDP',
    ftp_normal:'Параметр по умолчанию'

  },
  time: {
    name: 'Время',
    day_time: 'День/Время',
    start_time: 'Время начала',
    end_time: 'Время конца',
    to: 'To',
    monday: 'понедельник',
    tuesday: 'Вторник.',
    wednesday: 'среда',
    thursday: 'среда',
    friday: 'пятница',
    saturday: 'Суббота',
    weekday: 'воскресенье',
    mouse_click: 'Пожалуйста, выберите время с помощью мыши',
    times_output: 'Время не может быть больше пяти'
  },
  platform_settings: {
    gb28181: 'GB28181',
    onvif: 'ONVIF'
  },
  devices_maintenance: {
    about_devices: 'Об устройстве',
    devices_name: 'Имя устройства',
    devices_time: 'Время',
    software_version: 'Версия устройства',
    firmware_version: 'Версия прошивка',
    system_maintenance: 'Обслуживание системы',
    use_ntp: 'Использовать NTP',
    use_computer: 'Синхронизация с ПК'

  },
  osd: {
    basic_settings: 'Базовые настройки',
    system_settings: 'Системные настройки',
    custom_settings: 'Пользовательские настройки',
    font_size: 'Размер передней части',
    pellucidity: 'Прозрачность.',
    use_title: 'Включить заголовок',
    color: 'Цвет',
    use: 'открыт ',
    add_info: 'Наложенная информация',
    custom_centent: 'Пользовательский контент',
    add_infos: {
      rr: 'Разрешающая способность',
      rpfr: 'Разрешающая способность & Частот кадр',
      rpfrcr: 'Разрешающая способность & Частот кадр & Уровен ярд'
    }
  },
  area: {
    red: 'Зеленый',
    green: 'Зеленый',
    yellow: ' качество',
    blue: ' качество'
  }
}
