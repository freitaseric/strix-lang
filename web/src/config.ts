export const SITE = {
  website: "https://strix-lang.vercel.app/",
  author: "Eric Freitas",
  profile: "https://github.com/freitaseric",
  desc: "A WIP low-level, compiled, fast programming language",
  title: "Strix Language",
  ogImage: "astropaper-og.jpg",
  lightAndDarkMode: true,
  postPerIndex: 4,
  postPerPage: 4,
  scheduledPostMargin: 15 * 60 * 1000, // 15 minutes
  showArchives: true,
  showBackButton: true,
  editPost: {
    enabled: true,
    text: "Suggest Changes",
    url: "https://github.com/freitaseric/strix-lang/edit/main/",
  },
  dynamicOgImage: true,
  lang: "en",
  timezone: "America/Boa_Vista",
} as const;
