export const SITE = {
  website: "https://strix-lang.vercel.app/",
  author: "Eric Freitas",
  profile: "https://github.com/freitaseric",
  desc: "Uma linguagem de programação de baixo nível, com sitaxe de alto nível",
  title: "Linguagem Strix",
  ogImage: "astropaper-og.jpg",
  lightAndDarkMode: true,
  postPerIndex: 4,
  postPerPage: 4,
  scheduledPostMargin: 15 * 60 * 1000, // 15 minutes
  showArchives: true,
  showBackButton: true,
  editPost: {
    enabled: true,
    text: "Sugerir Modificações",
    url: "https://github.com/freitaseric/strix-lang/edit/main/",
  },
  dynamicOgImage: true,
  lang: "pt-br",
  timezone: "America/Boa_Vista",
} as const;
